/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:51:34 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/21 09:15:16 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int			sectlst_append_32(t_env *e, t_sectlst **sectlst, t_load_cmd *lc)
{
	t_section		*s;
	t_sectlst		*tmp;
	size_t			i;

	s = (t_section *)((char *)lc + sizeof(t_segment_cmd));
	tmp = NULL;
	i = 0;
	while (i < rev_uint32_endian(((t_segment_cmd *)lc)->nsects, e->rev))
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

char		*get_section_name_by_id_32(t_sectlst *sectlst, t_uint nb)
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
