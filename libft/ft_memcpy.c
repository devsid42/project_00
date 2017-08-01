/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:53:27 by avasseur          #+#    #+#             */
/*   Updated: 2016/04/13 16:46:28 by xubuntu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*tmp_src;
	char		*tmp_dst;

	if (dst != NULL && src != NULL)
	{
		i = 0;
		tmp_src = src;
		tmp_dst = dst;
		while (i < n)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
		return (dst);
	}
	return (NULL);
}
