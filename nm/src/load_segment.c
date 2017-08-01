/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:46:19 by avasseur          #+#    #+#             */
/*   Updated: 2017/03/10 15:46:33 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		load_segment(t_load_cmd *lc)
{
	t_segment_cmd_64	*seg;
	t_section_64		*sect;
	size_t				i;

	ft_putstr(" LC_SEGMENT_64:\n");
	seg = (t_segment_cmd_64 *)lc;
	sect = (t_section_64 *)((char *)lc + sizeof(t_segment_cmd_64));
	ft_printf(1, "seg->segname: %s\n", seg->segname);
	i = 0;
	while (i < seg->nsects)
	{
		ft_printf(1, "sectname: %s\n", sect->sectname);
		i += 1;
		sect += 1;
	}
	return (0);
}
