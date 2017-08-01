/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:15:19 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/21 09:17:14 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int	foreach_section(t_env *e)
{
	t_uint			i;
	t_sect_text		text;

	i = 0;
	e->sect = ((void *)e->lc) + sizeof(t_segment_cmd_64);
	while (i < rev_uint32_endian(e->seg->nsects, e->rev))
	{
		if (ft_strncmp(e->sect->sectname, SECT_TEXT, 6) == 0
			|| e->opt_all)
		{
			ft_printf(1, "Contents of (%s,", e->sect->segname);
			ft_printf(1, "%s) section\n", e->sect->sectname);
			text.map_offset = (char *)(e->map +\
				rev_uint32_endian(e->sect->offset, e->rev));
			text.size = rev_uint64_endian(e->sect->size, e->rev);
			text.addr = rev_uint64_endian(e->sect->addr, e->rev);
			if (e->magic == 0xcefaedfe)
				e->is_ppc = 1;
			ft_puthexmem(&text, 16, e->is_ppc);
			e->is_ppc = 0;
		}
		i += 1;
		e->sect = ((void *)e->sect) + sizeof(t_section_64);
	}
	return (0);
}

int			handle_64b_binary(t_env *e)
{
	t_uint	i;

	i = 0;
	e->is_32 = 0;
	e->hdr = (t_header_64 *)e->map;
	e->m_ptr = e->map + sizeof(t_header_64);
	while (i < rev_uint32_endian(e->hdr->ncmds, e->rev))
	{
		e->lc = (t_load_cmd *)e->m_ptr;
		if (rev_uint32_endian(e->lc->cmd, e->rev) == LC_SEGMENT_64)
		{
			e->seg = (t_segment_cmd_64 *)e->m_ptr;
			e->sect = (t_section_64 *)(e->m_ptr + sizeof(t_segment_cmd_64));
			if (e->opt_all == 1
				|| ft_strncmp(e->seg->segname, SEG_TEXT, 6) == 0
				|| ft_strncmp(e->sect->sectname, SECT_TEXT, 6) == 0)
			{
				foreach_section(e);
			}
		}
		e->m_ptr = e->m_ptr + rev_uint32_endian(e->lc->cmdsize, e->rev);
		i += 1;
	}
	return (0);
}

static int	foreach_section_32(t_env *e)
{
	t_uint			i;
	t_sect_text		text;

	i = 0;
	e->sect_32 = ((void *)e->lc) + sizeof(t_segment_cmd);
	while (i < rev_uint32_endian(e->seg_32->nsects, e->rev))
	{
		if (ft_strncmp(e->sect_32->sectname, SECT_TEXT, 6) == 0
			|| e->opt_all)
		{
			ft_printf(1, "Contents of (%s,", e->sect_32->segname);
			ft_printf(1, "%s) section\n", e->sect_32->sectname);
			text.map_offset = (char *)(e->map +\
				rev_uint32_endian(e->sect_32->offset, e->rev));
			text.size = rev_uint32_endian(e->sect_32->size, e->rev);
			text.addr = rev_uint32_endian(e->sect_32->addr, e->rev);
			if (e->magic == 0xcefaedfe)
				e->is_ppc = 1;
			ft_puthexmem(&text, 8, e->is_ppc);
			e->is_ppc = 0;
		}
		i += 1;
		e->sect_32 = ((void *)e->sect_32) + sizeof(t_section);
	}
	return (0);
}

int			handle_32b_binary(t_env *e)
{
	t_uint	i;

	i = 0;
	e->is_32 = 1;
	e->hdr_32 = (t_header *)e->map;
	e->m_ptr = e->map + sizeof(t_header);
	while (i < rev_uint32_endian(e->hdr_32->ncmds, e->rev))
	{
		e->lc = (t_load_cmd *)e->m_ptr;
		if (rev_uint32_endian(e->lc->cmd, e->rev) == LC_SEGMENT)
		{
			e->seg_32 = (t_segment_cmd *)e->m_ptr;
			e->sect_32 = (t_section *)(e->m_ptr + sizeof(t_segment_cmd));
			if (e->opt_all == 1
				|| ft_strncmp(e->seg_32->segname, SEG_TEXT, 6) == 0
				|| ft_strncmp(e->sect_32->sectname, SECT_TEXT, 6) == 0)
			{
				foreach_section_32(e);
			}
		}
		e->m_ptr = e->m_ptr + rev_uint32_endian(e->lc->cmdsize, e->rev);
		i += 1;
	}
	return (0);
}
