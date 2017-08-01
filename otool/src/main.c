/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:27:26 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/21 09:17:48 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int		otool(t_env *e, t_cchar *bin)
{
	if (ft_strncmp(e->map, ARMAG, SARMAG) != 0
		&& e->magic != FAT_MAGIC && e->magic != FAT_CIGAM)
		ft_printf(1, "%s:\n", bin);
	e->hdr = (t_header_64 *)e->map;
	if (e->opt_hdr)
	{
		put_header_64(e->hdr);
		if (!e->opt_all)
			return (0);
	}
	if (e->magic == MH_MAGIC || e->magic == MH_CIGAM)
		handle_32b_binary(e);
	else if (e->magic == MH_MAGIC_64 || e->magic == MH_CIGAM_64)
		handle_64b_binary(e);
	else if (e->magic == FAT_MAGIC || e->magic == FAT_CIGAM)
		handle_fat(e, bin);
	else if (ft_strncmp(e->map, ARMAG, SARMAG) == 0)
		handle_archive(e, bin);
	else
		ft_printf(1, "The file was not recognized as a valid object file.\n");
	return (0);
}

int		main(int argc, char **argv)
{
	t_env		e;
	int			opt_nbr;
	t_uint		i;

	if (argc < 2)
		usage(argv[0]);
	else
	{
		if ((opt_nbr = option(&e, argv)) == argc - 1 || opt_nbr == -1)
			usage(argv[0]);
		else
		{
			i = 1;
			while (argv[i])
			{
				if (*argv[i] != '-' && init_env(&e, argv[0], argv[i]) > -1)
				{
					otool(&e, argv[i]);
					drop_map(e.map_origin, e.map_size);
				}
				i += 1;
			}
		}
	}
	return (0);
}
