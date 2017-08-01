/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 20:41:06 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/09 15:32:27 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuphex(int n)
{
	int	i;

	if (n >= 16)
	{
		ft_putuphex(n / 16);
		ft_putuphex(n % 16);
		return ;
	}
	i = 10;
	while (i <= 15)
	{
		if (i == n)
			ft_putchar(n + 'A' - 10);
		i++;
	}
	if (n < 10 || n > 15)
		ft_putnbr(n);
}
