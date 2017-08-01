/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoahex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 21:27:54 by avasseur          #+#    #+#             */
/*   Updated: 2015/06/01 20:53:32 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_uint	ft_count_ten(unsigned long n, size_t base)
{
	unsigned int	i;
	unsigned int	remainder;

	remainder = 0;
	remainder = (unsigned int)remainder;
	i = 0;
	while (n > 0)
	{
		remainder = n % base;
		n = n / base;
		i++;
	}
	return (i);
}

char			*ft_itoahex(unsigned long n, char lower_upper)
{
	char			*s;
	unsigned int	remainder;
	unsigned int	i;

	if (n == 0)
		return (s = ft_strdup("0"));
	i = ft_count_ten(n, 16);
	s = ft_memalloc(sizeof(s) * ft_count_ten(n, 16) + 1);
	while (n > 0 && i > 0)
	{
		remainder = n % 16;
		n = n / 16;
		s[i - 1] = ft_itochex(remainder, lower_upper);
		i--;
	}
	return (s);
}
