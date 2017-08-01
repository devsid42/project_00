/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 00:04:14 by avasseur          #+#    #+#             */
/*   Updated: 2015/02/02 16:38:03 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(const char *s1, const char *s2, const char c)
{
	size_t		i;
	char		*tmp;
	size_t		len;

	if (!s2)
		return (NULL);
	len = ft_strlen(s1);
	if (!(tmp = ft_memalloc(sizeof(char) * (len + ft_strlen(s2)) + 1)))
		return (NULL);
	if (s1)
		ft_strncpy(tmp, s1, len);
	i = 0;
	while (s2[i] != c && i < ft_strlen(s2) && s2[i] != '\0')
	{
		tmp[len + i] = s2[i];
		i++;
	}
	return (tmp);
}
