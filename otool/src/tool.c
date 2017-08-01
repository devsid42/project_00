/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:54:27 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/13 18:04:51 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

uint32_t	swap_uint32(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}

uint32_t	rev_uint32_endian(uint32_t val, int active)
{
	if (active == 1)
	{
		val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
		val = (val << 16) | (val >> 16);
		return (val);
	}
	return (val);
}

uint64_t	rev_uint64_endian(uint64_t val, int active)
{
	if (active == 1)
	{
		val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
		val = (val << 16) | (val >> 16);
		return (val);
	}
	return (val);
}

int			is_rev_endian(t_uint magic)
{
	if (magic == MH_CIGAM || magic == MH_CIGAM_64 || magic == FAT_CIGAM)
		return (1);
	return (0);
}

int			set_magic_rev(void *map, t_uint *magic, int *rev)
{
	if (!map || !rev)
		return (-1);
	*magic = *((t_uint *)map);
	if (is_rev_endian(*magic) == 1)
		*rev = 1;
	else
		*rev = 0;
	return (0);
}
