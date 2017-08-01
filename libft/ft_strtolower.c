/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 22:29:14 by avasseur          #+#    #+#             */
/*   Updated: 2016/04/01 11:37:17 by xubuntu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *s, size_t limit)
{
	size_t	i;

	i = 0;
	if (!s || !*s)
		return (s);
	if (limit == 0)
		limit = ft_strlen(s);
	while (s[i] && i < limit)
	{
		s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}
