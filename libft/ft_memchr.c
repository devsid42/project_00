/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:49:09 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:23:06 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const char unsigned		*tmp;

	if (s != NULL)
	{
		tmp = s;
		i = 0;
		while (i < n)
		{
			if (*tmp == (unsigned char)c)
				return ((void *)tmp);
			tmp++;
			i++;
		}
	}
	return (NULL);
}
