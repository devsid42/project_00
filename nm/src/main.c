/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:26:50 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/21 09:12:46 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	init_base(t_env *e)
{
	e->map = e->map_origin;
	e->filetype = ((t_header_64 *)e->map)->filetype;
	e->magic_origin = *((int *)e->map);
	set_magic_rev(e->map, &e->magic, &e->rev_origin);
}

static int	nm(t_env *e, char *bin)
{
	if (binary2map(bin, &e->map_origin, &e->map_size) < 0)
		return (-1);
	init_base(e);
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
	if (ft_munmap((void *)&(e->map_origin), e->map_size) < 0)
		return (-1);
	return (0);
}

int			main(int argc, char **argv)
{
	size_t	i;
	t_env	e;
	size_t	opt_nbr;

	i = 1;
	if (argc < 2)
		usage(argv[0]);
	else
	{
		if ((opt_nbr = option(&e, argv)) == (size_t)argc - 1)
			usage(argv[0]);
		while (argv[i])
		{
			if (*argv[i] != '-')
			{
				if (argc - opt_nbr > 2)
					ft_printf(1, "\n%s:\n", argv[i]);
				nm(&e, argv[i]);
				opt_nbr = option(&e, argv);
			}
			++i;
		}
	}
	return (EXIT_SUCCESS);
}
