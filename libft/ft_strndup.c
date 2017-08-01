/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:36:11 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:19:23 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t		i;
	char		*cpy;

	if (s1 != NULL)
	{
		i = 0;
		cpy = (char *)malloc(sizeof(cpy) * ft_strlen(s1) + 1);
		while (s1[i] != '\0' && i < n)
		{
			cpy[i] = s1[i];
			i++;
		}
		cpy[i] = '\0';
		return (cpy);
	}
	return (NULL);
}
