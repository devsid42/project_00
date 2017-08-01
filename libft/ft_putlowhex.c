/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlowhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 20:41:06 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/19 20:31:08 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlowhex(int n)
{
	int		i;

	if (n >= 16)
	{
		ft_putlowhex(n / 16);
		ft_putlowhex(n % 16);
		return ;
	}
	i = 10;
	while (i <= 15)
	{
		if (i == n)
			ft_putchar(n + 'a' - 10);
		i++;
	}
	if (n < 10)
		ft_putnbr(n);
}
