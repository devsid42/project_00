/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:29:13 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:24:25 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		len;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		len = ft_strlen(s1);
		while (s2[i] != '\0' && i < n)
		{
			s1[i + len] = s2[i];
			i++;
		}
		s1[i + len] = '\0';
		return (s1);
	}
	return (NULL);
}
