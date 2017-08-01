/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:23:47 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/30 03:36:34 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_a(int i, int len, char *s, int n)
{
	int		tmp;

	if (n == -2147483647 - 1)
		return (ft_strdup("-2147483648"));
	else if (n == 2147483647)
		return (ft_strdup("2147483647"));
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

char		*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		i;

	len = ft_intlen(n);
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
