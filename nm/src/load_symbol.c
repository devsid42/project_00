/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_symtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:50:06 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/21 09:07:46 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	get_symbol_name_32(t_env *e, char *strtab, t_nlist *sym_table,\
								t_uint i)
{
	t_symlst		*symlst;

	symlst = NULL;
	symlst = (t_symlst *)ft_memalloc(sizeof(t_symlst));
	symlst->addr = rev_uint32_endian(sym_table[i].n_value, e->rev);
	symlst->nsect = rev_uint32_endian(sym_table[i].n_sect, e->rev);
	symlst->type = rev_uint32_endian(sym_table[i].n_type, e->rev);
	symlst->desc = rev_uint32_endian(sym_table[i].n_desc, e->rev);
	symlst->symtab = (int *)&(sym_table[i]);
	symlst->name = strtab + rev_uint32_endian(sym_table[i].n_un.n_strx, e->rev);
	symlst->next = NULL;
	if (symlst->type == 0x24)
		symlst->type = 0xf;
	else if (symlst->type == 0x26)
		symlst->type = 0xe;
	symlst_append(&e->symlst, symlst);
	return (0);
}

static int	get_symbol_name(t_env *e, char *strtab,\
			t_nlist_64 *sym_table, t_uint i)
{
	t_symlst		*symlst;

	symlst = NULL;
	symlst = (t_symlst *)ft_memalloc(sizeof(t_symlst));
	symlst->addr = rev_uint64_endian(sym_table[i].n_value, e->rev);
	symlst->nsect = rev_uint32_endian(sym_table[i].n_sect, e->rev);
	symlst->type = rev_uint32_endian(sym_table[i].n_type, e->rev);
	symlst->desc = rev_uint32_endian(sym_table[i].n_desc, e->rev);
	symlst->symtab = (int *)&(sym_table[i]);
	symlst->name = strtab + rev_uint32_endian(sym_table[i].n_un.n_strx, e->rev);
	symlst->next = NULL;
	if (symlst->type == 0x24)
		symlst->type = 0xf;
	else if (symlst->type == 0x26)
		symlst->type = 0xe;
	symlst_append(&e->symlst, symlst);
	return (0);
}

static void	load_symbol_p2(t_env *e, char *strtab, void *symtab, t_uint i)
{
	int				offset;
	char			*name;

	if (e->is_32 == 1)
	{
		name = strtab +\
			rev_uint32_endian(((t_nlist *)symtab)[i].n_un.n_strx, e->rev);
		offset = rev_uint32_endian(((t_nlist *)symtab)[i].n_value, e->rev);
		if (sym_accept_condition(e, name, offset) == 1)
			get_symbol_name_32(e, strtab, symtab, i);
	}
	else
	{
		name = strtab +\
			rev_uint32_endian(((t_nlist_64 *)symtab)[i].n_un.n_strx, e->rev);
		offset = rev_uint32_endian(((t_nlist_64 *)symtab)[i].n_value, e->rev);
		if (sym_accept_condition(e, name, offset) == 1)
			get_symbol_name(e, strtab, symtab, i);
	}
}

int			load_symbol(t_env *e)
{
	char			*strtab;
	void			*symtab;
	t_uint			i;
	t_symtab_cmd	*sym;

	i = 0;
	sym = (t_symtab_cmd *)e->lc;
	strtab = e->map + rev_uint32_endian(sym->stroff, e->rev);
	symtab = (void *)e->map + rev_uint32_endian(sym->symoff, e->rev);
	while (i < rev_uint32_endian(sym->nsyms, e->rev))
	{
		load_symbol_p2(e, strtab, symtab, i);
		i += 1;
	}
	return (0);
}
