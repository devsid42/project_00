/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:04:10 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:24:18 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_d(const char *s)
{
	size_t	i;

	if (!s)
	{
		ft_putstr("(strlen_d null)\n");
		return (0);
	}
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
