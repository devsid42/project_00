/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:26:50 by avasseur          #+#    #+#             */
/*   Updated: 2017/03/23 16:08:51 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int			symlst_append(t_symlst **symlst, t_symlst *newlst)
{
	t_symlst	*lst;

	if (!symlst || !newlst)
		return (-1);
	if (!*symlst)
	{
		*symlst = newlst;
		return (1);
	}
	lst = *symlst;
	while (lst->next)
		lst = lst->next;
	lst->next = newlst;
	return (0);
}

int			symlst_add_type_letter(t_symlst *symlst, t_sectlst *sectlst)
{
	t_symlst	*lst;
	char		*name;

	if (!symlst || !sectlst)
		return (-1);
	lst = symlst;
	while (lst)
	{
		name = get_section_name_by_id(sectlst, lst->nsect);
		lst->type_letter = type(name, lst->type, lst->addr, lst->nsect);
		lst = lst->next;
	}
	return (0);
}

int			symlst_delete_dup(t_symlst *symlst)
{
	t_symlst	*l;
	t_symlst	*del;

	if (!symlst)
		return (-1);
	l = symlst;
	del = NULL;
	while (l->next)
	{
		if (ft_strcmp(l->name, l->next->name) == 0
			&& l->addr == 0)
		{
			symlst_swap(l, l->next);
			if (l->next->next)
			{
				del = l->next;
				free(del);
				l->next = l->next->next;
			}
		}
		l = l->next;
	}
	return (0);
}

int			symlst_delete(t_symlst *symlst)
{
	if (!symlst)
		return (-1);
	while (symlst)
	{
		free(symlst);
		symlst = symlst->next;
	}
	return (0);
}
