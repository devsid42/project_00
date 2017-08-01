/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:07:11 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:24:37 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0' && i < maxlen)
			i++;
		return (i);
	}
	return (0);
}
