/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:51:34 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/06 14:51:36 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

char		*put_section(t_segment_cmd_64 *seg)
{
	t_section_64		*sect;
	size_t				i;
	static size_t		ipi;

	sect = (t_section_64 *)((char *)seg + sizeof(t_segment_cmd_64));
	i = 0;
	while (i < seg->nsects)
	{
		ft_printf(1, "sectname[%d]: %s\n", ipi + 1, sect->sectname);
		i += 1;
		ipi += 1;
		sect += 1;
	}
	return (NULL);
}

int			sectlst_delete(t_sectlst *sectlst)
{
	if (!sectlst)
		return (EXIT_FAILURE);
	while (sectlst)
	{
		free(sectlst);
		sectlst = sectlst->next;
	}
	return (EXIT_SUCCESS);
}

int			sectlst_append_loop(t_sectlst **sectlst, char *sectname,\
				t_sectlst *tmp)
{
	t_sectlst			*lst;

	lst = *sectlst;
	if (!*sectlst)
	{
		tmp->name = sectname;
		tmp->next = NULL;
		*sectlst = tmp;
	}
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = tmp;
		tmp->name = sectname;
		tmp->next = NULL;
	}
	return (0);
}

int			sectlst_append(t_env *e, t_sectlst **sectlst, t_load_cmd *lc)
{
	t_section_64		*s;
	t_sectlst			*tmp;
	size_t				i;

	s = (t_section_64 *)((char *)lc + sizeof(t_segment_cmd_64));
	tmp = NULL;
	i = 0;
	while (i < rev_uint32_endian(((t_segment_cmd_64 *)lc)->nsects, e->rev))
	{
		if (!(tmp = (t_sectlst *)ft_memalloc(sizeof(t_sectlst))))
			return (-1);
		if (sectlst_append_loop(sectlst, s->sectname, tmp) == -1)
			return (-1);
		s += 1;
		i += 1;
	}
	return (1);
}

char		*get_section_name_by_id(t_sectlst *sectlst, t_uint nb)
{
	t_sectlst	*lst;
	t_uint		i;

	if (!sectlst || nb == 0)
		return (NULL);
	lst = sectlst;
	i = 1;
	while (lst && i < nb)
	{
		lst = lst->next;
		i += 1;
	}
	if (!lst)
		return (NULL);
	return (lst->name);
}
