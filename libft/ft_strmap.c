/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:46:01 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:15:15 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t	i;
	char	*tmp;
	size_t	len;

	i = 0;
	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		tmp = (char *)malloc(sizeof(tmp) * len);
		while (i < len)
		{
			tmp[i] = f(s[i]);
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
