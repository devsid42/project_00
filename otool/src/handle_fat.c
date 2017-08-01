/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:51:03 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/21 09:08:19 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int	is_same_arch(t_env *e)
{
	uint32_t	x;
	t_fat_arch	*arch;
	void		*m_ptr;

	m_ptr = e->map_origin;
	x = rev_uint32_endian(((t_fat_hdr*)m_ptr)->nfat_arch, e->rev_origin);
	arch = (void *)m_ptr + sizeof(t_fat_hdr);
	while (x)
	{
		if (is_mapped(e, (void *)arch) == 0)
			return (-1);
		m_ptr = e->map_origin + rev_uint32_endian(arch->offset, e->rev_origin);
		set_magic_rev(m_ptr, &e->magic, &e->rev);
		arch = ((void *)arch) + sizeof(t_fat_arch);
		x -= 1;
		if (x)
		{
			m_ptr = e->map_origin + rev_uint32_endian(arch->offset,\
				e->rev_origin);
			if (is_rev_endian(*((t_uint *)m_ptr)) == is_rev_endian(e->magic))
				return (1);
			return (0);
		}
	}
	return (0);
}

static void	init_handle_fat(t_env *e, t_cchar *bin, t_fat_arch *arch)
{
	e->map = e->map_origin + rev_uint32_endian(arch->offset, e->rev_origin);
	e->magic = *((t_uint *)e->map);
	set_magic_rev(e->map, &e->magic, &e->rev);
	ft_printf(1, "%s (arch: 0x%x):\n", bin, e->magic);
}

static int	launcher(t_env *e, t_cchar *bin)
{
	int		res;

	res = 0;
	if (e->magic == MH_MAGIC || e->magic == MH_CIGAM)
		res = handle_32b_binary(e);
	else if (e->magic == MH_MAGIC_64 || e->magic == MH_CIGAM_64)
		res = handle_64b_binary(e);
	else if (e->magic == FAT_MAGIC || e->magic == FAT_CIGAM)
		res = handle_fat(e, bin);
	else if (ft_strncmp(e->map, ARMAG, SARMAG) == 0)
		res = handle_archive(e, bin);
	return (res);
}

int			handle_fat(t_env *e, t_cchar *bin)
{
	uint32_t	x;
	t_fat_arch	*arch;

	x = rev_uint32_endian(((t_fat_hdr*)e->map)->nfat_arch, e->rev_origin);
	arch = (void *)e->map + sizeof(t_fat_hdr);
	if (is_same_arch(e) == 1)
	{
		x = 1;
		arch = ((void *)arch) + sizeof(t_fat_arch);
	}
	while (x)
	{
		if (is_mapped(e, (void *)arch) == 0)
			return (-1);
		init_handle_fat(e, bin, arch);
		if (launcher(e, bin) == -1)
			return (-1);
		arch = ((void *)arch) + sizeof(t_fat_arch);
		x -= 1;
	}
	return (0);
}
