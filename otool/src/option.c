/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:12:11 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/13 16:15:03 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void	init_option(t_env *e, int *opt_nbr)
{
	e->verbose = 0;
	e->opt_hdr = 0;
	e->opt_all = 0;
	e->is_32 = 0;
	*opt_nbr = 0;
}

int			option(t_env *e, char **argv)
{
	t_uint	i;
	int		opt_nbr;

	i = 0;
	init_option(e, &opt_nbr);
	while (argv[i])
	{
		if (*argv[i] == '-')
		{
			if (ft_strncmp(argv[i], "-v", 2) == 0)
				e->verbose = 1;
			else if (ft_strncmp(argv[i], "-a", 2) == 0)
				e->opt_all = 1;
			else if (ft_strncmp(argv[i], "-h", 2) == 0)
				e->opt_hdr = 1;
			else
			{
				ft_printf(1, "Bad option: `%s'\n", argv[i]);
				return (-1);
			}
			opt_nbr += 1;
		}
		i += 1;
	}
	return (opt_nbr);
}
