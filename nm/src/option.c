/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:51:22 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/06 14:51:24 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	init_env(t_env *e, char *app)
{
	e->x_opt = 0;
	e->no_sort_opt = 0;
	e->verbose = 0;
	e->is_32 = 0;
	e->rev = 0;
	e->app = app;
}

int			option(t_env *e, char **argv)
{
	int		i;
	size_t	opt_nbr;

	i = 0;
	opt_nbr = 0;
	init_env(e, argv[0]);
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			opt_nbr += 1;
			if (ft_strncmp(argv[i], "-x", 2) == 0)
				e->x_opt = 1;
			else if (ft_strncmp(argv[i], "-X", 2) == 0)
				e->x_opt = 2;
			else if (ft_strncmp(argv[i], "-p", 2) == 0)
				e->no_sort_opt = 1;
			else
				usage(*argv);
		}
		i += 1;
	}
	return (opt_nbr);
}
