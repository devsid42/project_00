/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:16:42 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/21 09:18:39 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static size_t	ft_sizehexlen(size_t n)
{
	size_t	len;

	if (n < 16)
		return (1);
	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void		fill_output(char c, uint64_t origin_nbr, size_t max_len)
{
	size_t	i;
	size_t	origin_nbr_len;
	size_t	res;

	i = 0;
	origin_nbr_len = ft_sizehexlen(origin_nbr);
	res = max_len - origin_nbr_len;
	if (origin_nbr_len > max_len)
		res = origin_nbr_len - max_len;
	while (i < res)
	{
		ft_putchar(c);
		i += 1;
	}
}

static void		put_addr_puthexmem(size_t i, t_sect_text *txt, size_t max_len)
{
	if (i % 16 == 0)
	{
		fill_output('0', txt->addr, max_len);
		ft_printf(1, "%x\t", txt->addr);
	}
}

void			ft_puthexmem(t_sect_text *txt, size_t max_len, int is_ppc)
{
	size_t	i;

	if (txt && txt->map_offset)
	{
		i = 0;
		while (i < txt->size)
		{
			put_addr_puthexmem(i, txt, max_len);
			if (((t_uchar *)txt->map_offset)[i] <= 0xf)
				ft_putchar('0');
			ft_printf(1, "%x", ((t_uchar *)txt->map_offset)[i]);
			i += 1;
			txt->addr += 1;
			if (is_ppc == 0)
				ft_putchar(' ');
			else if (is_ppc == 1 && i % 4 == 0)
				ft_putchar(' ');
			if (i % 16 == 0 && i > 0)
				ft_putstr("\n");
		}
		if (i % 16 > 0)
			ft_putstr("\n");
	}
}

void			put_header_64(t_header_64 *hdr)
{
	ft_printf(1, "- MAC header -\n");
	ft_printf(1, " magic: 0x%x\n", hdr->magic);
	ft_printf(1, " cputype: %d\n", hdr->cputype);
	ft_printf(1, " cpusubtype: 0x%x\n", (char)hdr->cpusubtype);
	ft_printf(1, " filetype: %d\n", hdr->filetype);
	ft_printf(1, " ncmds: %d\n", hdr->ncmds);
	ft_printf(1, " sizeofcmds: %d\n", hdr->sizeofcmds);
	ft_printf(1, " flags: 0x%x\n", hdr->flags);
	ft_putstr(RESET);
}
