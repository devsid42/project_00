/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:26:30 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:19:58 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		if (s2[0] == '\0')
			return ((char *)s1);
		while (s1[i] && i < n)
		{
			while (s1[i + j] == s2[j] && s1[i + j] && s2[j] && (i + j) < n)
			{
				if (s2[j + 1] == '\0')
					return (&((char*)s1)[i]);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}
