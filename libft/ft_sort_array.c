/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 12:52:46 by avasseur          #+#    #+#             */
/*   Updated: 2017/03/10 12:53:14 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_sort_array(char **a)
{
	size_t	i;
	int		check;

	i = 0;
	while (a && a[i] && a[1 + i])
	{
		check = 0;
		if (ft_strcmp(a[i], a[1 + i]) > 0)
		{
			check = 1;
			ft_swap_ptr(&a[i], &a[1 + i]);
		}
		if (check == 0)
			i += 1;
		else
			i = 0;
	}
	return (a);
}
