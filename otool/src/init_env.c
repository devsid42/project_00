/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:12:41 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/13 16:13:27 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int	set_secure_env(t_env *e)
{
	if (!e)
	{
		ft_printf(1, "[!] No env variable\n");
		return (-1);
	}
	e->app = NULL;
	e->map = NULL;
	e->map_origin = NULL;
	e->fat_map = NULL;
	e->m_ptr = NULL;
	e->hdr = NULL;
	e->lc = NULL;
	e->seg = NULL;
	e->is_swap = 0;
	e->is_gnl = 0;
	return (0);
}

int			init_env(t_env *e, t_cchar *app, t_cchar *binary)
{
	if (set_secure_env(e) < 0)
		return (-1);
	if (binary2map(binary, &e->map_origin, &e->map_size) == -1)
		return (-1);
	e->map = e->map_origin;
	e->app = app;
	e->magic_origin = *((int *)e->map);
	e->magic = e->magic_origin;
	e->filetype = ((t_header_64 *)e->map)->filetype;
	set_magic_rev(e->map_origin, &e->magic_origin, &e->rev_origin);
	return (0);
}
