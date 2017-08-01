/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:12:31 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:22:50 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	const char		*tmp_src;
	char			*tmp_dst;

	if (dst && src && n)
	{
		i = 0;
		tmp_src = src;
		tmp_dst = dst;
		while (i < n)
		{
			if (tmp_src[i] == c)
			{
				tmp_dst[i] = tmp_src[i];
				i++;
				return (tmp_dst + i);
			}
			tmp_dst[i] = tmp_src[i];
			i++;
		}
		return (NULL);
	}
	return (NULL);
}
