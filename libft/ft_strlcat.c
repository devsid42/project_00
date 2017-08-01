/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:33:22 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:23:54 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

	i = 0;
	if (src != NULL && dst != NULL)
	{
		slen = ft_strlen(src);
		dlen = ft_strlen(dst);
		if (dlen > size)
			return (slen + size);
		while (dlen + i < size - 1)
		{
			dst[dlen + i] = src[i];
			i++;
		}
		dst[dlen + i] = '\0';
		return (dlen + slen);
	}
	return (0);
}
