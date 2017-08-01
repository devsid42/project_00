/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strocc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:58:32 by avasseur          #+#    #+#             */
/*   Updated: 2014/11/10 21:25:49 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strocc(const char *s, char c)
{
	size_t	i;
	size_t	y;

	if (s != NULL)
	{
		i = 0;
		y = 0;
		while (s[i] != '\0')
		{
			if (s[i] == c)
				y++;
			i++;
		}
		return (y);
	}
	return (0);
}
