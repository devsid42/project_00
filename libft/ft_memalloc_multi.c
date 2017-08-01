/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_multi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 20:35:29 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:11:30 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_memalloc_multi(size_t h_size, size_t v_size)
{
	void	**multi;
	size_t	i;

	if (h_size == 1 && v_size == 0)
		return ((void **)malloc(sizeof(multi) * 1));
	else if (h_size == 0 && v_size > 0)
		return ((void **)malloc(sizeof(multi) * v_size));
	else if (h_size > 0 && v_size > 0)
	{
		multi = ft_memalloc(sizeof(multi) * v_size);
		i = 0;
		while (i < v_size)
		{
			multi[i] = (char *)malloc(sizeof(multi) * h_size);
			i++;
		}
		return (multi);
	}
	return (NULL);
}
