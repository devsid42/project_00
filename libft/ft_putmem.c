/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 19:35:45 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:28:22 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmem(char *s, size_t n)
{
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		while (i < n)
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}