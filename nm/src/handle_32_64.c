/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32_64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 09:06:44 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/21 09:06:47 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	symlst_work(t_env *e)
{
	symlst_add_type_letter(e->symlst, e->sectlst);
	if (!e->no_sort_opt)
		symlst_sort(&e->symlst);
	symlst_delete_dup(e->symlst);
	symlst_show(e, e->symlst);
	symlst_delete(e->symlst);
	e->symlst = NULL;
	sectlst_delete(e->sectlst);
	e->sectlst = NULL;
}

int			handle_64b_binary(t_env *e)
{
	t_uint		i;

	e->lc = (t_load_cmd *)(e->map + sizeof(t_header_64));
	i = 0;
	e->sectlst = NULL;
	e->symlst = NULL;
	while (i < rev_uint32_endian(((t_header_64 *)e->map)->ncmds, e->rev))
	{
		if (is_mapped(e, e->lc) == 0)
			return (-1);
		if (rev_uint32_endian(e->lc->cmd, e->rev) == LC_SYMTAB)
			load_symbol(e);
		else if (rev_uint32_endian(e->lc->cmd, e->rev) == LC_SEGMENT_64)
		{
			if (sectlst_append(e, &e->sectlst, e->lc) < 0)
			{
				ft_printf(1, "[!] Error sectlst_append\n");
				return (-1);
			}
		}
		e->lc = (void *)e->lc + rev_uint32_endian(e->lc->cmdsize, e->rev);
		i += 1;
	}
	symlst_work(e);
	return (0);
}

int			handle_32b_binary(t_env *e)
{
	t_uint		i;

	e->lc = (t_load_cmd *)(e->map + sizeof(t_header));
	i = 0;
	e->sectlst = NULL;
	e->symlst = NULL;
	e->is_32 = 1;
	while (i < rev_uint32_endian(((t_header *)e->map)->ncmds, e->rev))
	{
		if (is_mapped(e, e->lc) == 0)
			return (-1);
		if (rev_uint32_endian(e->lc->cmd, e->rev) == LC_SYMTAB)
			load_symbol(e);
		else if (rev_uint32_endian(e->lc->cmd, e->rev) == LC_SEGMENT)
		{
			if (sectlst_append_32(e, &e->sectlst, e->lc) < 0)
				return (-1);
		}
		e->lc = ((void *)e->lc) + rev_uint32_endian(e->lc->cmdsize, e->rev);
		i += 1;
	}
	symlst_work(e);
	return (0);
}
