/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:30:17 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/30 03:39:20 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		if (!(tmp = ft_memalloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len && s[i + start] != '\0' && i + start <= ft_strlen(s))
		{
			tmp[i] = s[i + start];
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
