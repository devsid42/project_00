/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 17:30:44 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:14:45 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		while (s1[i] == s2[i])
		{
			if (s1[i] == '\0')
				return (0);
			i++;
		}
		if ((unsigned char)s1[i] - (unsigned char)s2[i] > 0)
			return (1);
		else if ((unsigned char)s1[i] - (unsigned char)s2[i] < 0)
			return (-1);
		else
			return (0);
	}
	return (0);
}
