/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:54:51 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/06 14:54:56 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	usage(const char *app)
{
	ft_printf(1, "Usage: %s -[xXp] <binary ...>\n", app);
	ft_printf(1, "\t-x Show type / nsect / desc\n");
	ft_printf(1, "\t-X Show type / type letter / nsect / desc\n");
	ft_printf(1, "\t-p Don't sort symbols (original sort)\n");
}
