/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulonglen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:45:47 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/21 15:39:34 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_longlen(long n)
{
	size_t	len;
	int		sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	if (n >= 0 && n < 10)
		return (1);
	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len + sign);
}
