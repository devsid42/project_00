/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:23:42 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:17:55 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if (s != NULL)
	{
		i = ft_strlen(s);
		while (s[i] != (char)c && i)
			i--;
		if (s[i] == (char)c)
			return ((char *)s + i);
		return (NULL);
	}
	return (NULL);
}
