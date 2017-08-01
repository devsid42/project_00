/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epurarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 02:09:24 by avasseur          #+#    #+#             */
/*   Updated: 2015/05/14 02:30:37 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_epurarray(char **a)
{
	char	**epur;
	size_t	i;

	if (!a)
		return (NULL);
	epur = NULL;
	if (!(epur = ft_memalloc(sizeof(char *) * (ft_arraylen(a) + 1))))
		return (NULL);
	i = 0;
	while (*a)
		epur[i++] = ft_epurstr(*a++);
	return (epur);
}
