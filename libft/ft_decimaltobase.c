/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimaltobase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 21:26:41 by avasseur          #+#    #+#             */
/*   Updated: 2015/03/03 23:09:08 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_ten(t_ll quotient, t_uint base)
{
	int		i;

	i = 0;
	while (quotient != 0)
	{
		quotient = quotient / base;
		i++;
	}
	return (i);
}

static t_ll		ft_greater_ten_rem(t_ll quotient, t_uint base, int max)
{
	t_ll		remainder;
	int			i;

	i = 0;
	while (i < max)
	{
		remainder = quotient % base;
		quotient = quotient / base;
		i++;
	}
	return (remainder);
}

t_ll			ft_decimaltobase(t_ll n, t_uint base)
{
	int			i;
	int			max;
	t_ll		remainder;
	t_ll		nbr;

	max = ft_count_ten(n, base);
	nbr = 0;
	i = 0;
	while (i < ft_count_ten(n, base))
	{
		remainder = ft_greater_ten_rem(n, base, max);
		nbr += remainder * (ft_power(10, max) / 10);
		max--;
		i++;
	}
	return (nbr);
}
