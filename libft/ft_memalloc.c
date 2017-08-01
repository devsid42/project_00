/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:02:33 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:11:22 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;
	char	*set;
	size_t	i;

	i = 0;
	if (!(s = (void *)malloc(sizeof(s) * size)))
		return (NULL);
	set = (void *)s;
	while (i < size)
	{
		set[i] = 0;
		i++;
	}
	return ((void *)s);
}
