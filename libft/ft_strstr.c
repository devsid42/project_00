/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:16:22 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:19:07 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	if (s2[0] == '\0' || s2 == NULL)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j])
			j++;
		else
		{
			j = 0;
			k++;
			i = k;
		}
		if (!s2[j])
			return ((char *)s1 + (i - (j - 1)));
		i++;
	}
	return (NULL);
}
