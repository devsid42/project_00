/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symlst_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:51:03 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/21 09:08:19 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int			symlst_swap(t_symlst *a, t_symlst *b)
{
	if (!a || !b)
		return (-1);
	ft_swap_ptr((void *)&a->addr, (void *)&b->addr);
	ft_swapi((int *)&a->nsect, (int *)&b->nsect);
	ft_swapc((char *)&a->type, (char *)&b->type);
	ft_swapc(&a->type_letter, &b->type_letter);
	ft_swapi((int *)&a->desc, (int *)&b->desc);
	ft_swapi((int *)&a->symtab, (int *)&b->symtab);
	ft_swap_ptr(&a->name, &b->name);
	return (0);
}

int			symlst_sort(t_symlst **symlst)
{
	t_symlst	*lst;

	if (!symlst || !*symlst)
		return (-1);
	lst = *symlst;
	while (lst->next)
	{
		if (ft_strcmp(lst->name, lst->next->name) > 0)
		{
			symlst_swap(lst, lst->next);
			lst = *symlst;
		}
		else
			lst = lst->next;
	}
	return (0);
}

int			symlst_is_name_exist(t_symlst *symlst, t_cchar *name)
{
	t_symlst	*lst;

	if (!symlst)
		return (0);
	lst = symlst;
	while (lst)
	{
		if (name && ft_strcmp(lst->name, name) == 0)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int			symlst_is_offset_exist(t_symlst *symlst, uint64_t offset)
{
	t_symlst	*lst;

	if (!symlst)
		return (0);
	lst = symlst;
	while (lst)
	{
		if (offset != 0 && lst->addr == offset)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int			sym_accept_condition(t_env *e, char *name, int offset)
{
	if (!e)
		return (-1);
	if (name && *name && *name != '/'
		&& symlst_is_offset_exist(e->symlst, offset) == 0
		&& *(ft_strlen(name) + name - 2) != '.'
		&& !ft_strstr(name, "radr://"))
	{
		return (1);
	}
	return (0);
}
