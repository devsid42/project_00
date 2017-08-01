/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:19:26 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/13 16:19:28 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void	usage(t_cchar *app)
{
	ft_printf(1, "Usage: %s [ah] <binary ...>\n", app);
	ft_printf(1, "\t -h Display header\n");
	ft_printf(1, "\t -a Display all seg/sect\n");
}
