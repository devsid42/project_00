/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:30:58 by avasseur          #+#    #+#             */
/*   Updated: 2015/02/02 15:31:05 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*cpy;

	if (s1 != NULL)
	{
		i = 0;
		if (!(cpy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
			return (NULL);
		while (s1[i] != '\0')
		{
			cpy[i] = s1[i];
			i++;
		}
		cpy[i] = '\0';
		return (cpy);
	}
	return (NULL);
}
