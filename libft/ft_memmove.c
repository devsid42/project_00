/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:26:43 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:12:00 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;

	if (dst != src)
	{
		if (!(tmp = ft_memalloc(sizeof(*tmp) * len + 1)))
			return (NULL);
		ft_memcpy(tmp, src, len);
		ft_memcpy(dst, tmp, len);
		free(tmp);
	}
	return (dst);
}
