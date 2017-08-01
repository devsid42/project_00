/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_archive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:51:03 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/21 09:08:19 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	arch_condition(t_env *e, char *ft_name, const char *bin,\
	t_ar_hdr *ar_hdr)
{
	ft_printf(1, "\n%s(%s):\n", bin, ft_name);
	e->map = (void *)ar_hdr + sizeof(t_ar_hdr) + e->extended;
	set_magic_rev(e->map, &e->magic, &e->rev);
	if (e->magic == MH_MAGIC || e->magic == MH_CIGAM)
		handle_32b_binary(e);
	else if (e->magic == MH_MAGIC_64 || e->magic == MH_CIGAM_64)
		handle_64b_binary(e);
	else
		ft_printf(1, "[!] Something wrong in this archive.\n");
}

static int	is_same(t_ar_hdr *ar_hdr, char *obj, int i, int nobj)
{
	char	*name;

	if (i < nobj)
	{
		name = ft_strchr(ar_hdr->ar_name, '\n') + 1;
		if (ft_strcmp(obj, name) == 0)
			return (1);
	}
	return (0);
}

int			handle_archive(t_env *e, const char *bin)
{
	t_ranlib		*ran;
	int				i;
	int				nobj;
	char			*ft_name;

	e->fat_map = e->map;
	i = 0;
	e->ar_hdr = (void*)e->map + SARMAG;
	e->extended = ft_atoi(e->ar_hdr->ar_name + ft_strlen(AR_EFMT1));
	ran = (t_ranlib *)((void*)e->map + sizeof(t_ar_hdr) + SARMAG + e->extended);
	nobj = *((int *)ran) / sizeof(t_ranlib);
	if (!is_mapped(e, e->map_origin + nobj * sizeof(t_ranlib)))
		return (-1);
	ft_printf(1, "%s %s: \n", e->app, bin);
	ran = ((void *)ran) + 4;
	while (i < nobj)
	{
		e->ar_hdr = (void *)e->fat_map + ran[i].ran_off;
		e->extended = ft_atoi(e->ar_hdr->ar_name + ft_strlen(AR_EFMT1));
		ft_name = ft_strchr(e->ar_hdr->ar_name, '\n') + 1;
		i++;
		if (is_same((void *)e->fat_map + ran[i].ran_off, ft_name, i, nobj) == 0)
			arch_condition(e, ft_name, bin, e->ar_hdr);
	}
	return (0);
}
