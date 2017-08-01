/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 00:04:14 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/30 03:35:14 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		i;
	char		*tmp;
	size_t		len1;

	if (!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	if (!(tmp = ft_memalloc(sizeof(char) * (len1 + ft_strlen(s2)) + 1)))
		return (NULL);
	if (s1)
		ft_strncpy(tmp, s1, len1);
	i = 0;
	while (i < ft_strlen(s2))
	{
		tmp[len1 + i] = s2[i];
		i++;
	}
	tmp[len1 + i] = '\0';
	return (tmp);
}
