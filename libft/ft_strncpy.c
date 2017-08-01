/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:30:46 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:16:07 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	int		clean;

	if (!src || !dst)
		return (NULL);
	i = 0;
	clean = 0;
	while (i < n)
	{
		if (src[i] == '\0')
			clean = 1;
		if (clean == 0)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
