/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnccmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: x <marvin@42.fr>                           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/10 15:01:55 by x                 #+#    #+#             */
/*   Updated: 2015/06/10 15:27:56 by x                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnccmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (i < n)
	{
		if (ft_toupper(s1[i]) == '\0' || ft_toupper(s2[i]) == '\0')
			return (s1[i] - s2[i]);
		else if (ft_toupper(s1[i]) != ft_toupper(s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
