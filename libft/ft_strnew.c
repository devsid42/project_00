/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:41:00 by avasseur          #+#    #+#             */
/*   Updated: 2015/06/26 23:35:32 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (s)
	{
		while (i < size + 1)
		{
			s[i] = '\0';
			i++;
		}
		return (s);
	}
	else
		return (NULL);
}
