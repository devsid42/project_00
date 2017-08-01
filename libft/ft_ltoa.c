/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:17:33 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/30 03:37:02 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_a(int i, int len, char *s, long n)
{
	long	tmp;

	while (len >= i)
	{
		tmp = n % 10;
		s[len] = tmp + '0';
		if (n == 10)
			n = 11;
		else
			n = n / 10;
		len--;
	}
	return (s);
}

char		*ft_ltoa(long n)
{
	char	*s;
	int		len;
	int		i;

	len = ft_longlen(n);
	i = 0;
	if (n != 0)
		s = ft_memalloc(sizeof(char) * len + 1);
	else
		return (ft_strdup("0"));
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
		i++;
	}
	return (ft_create_a(i, len - 1, s, n));
}
