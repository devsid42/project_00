/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_noprint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 00:25:02 by avasseur          #+#    #+#             */
/*   Updated: 2015/06/12 00:25:13 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace_noprint(char *s)
{
	int		i;

	i = 0;
	while (s && s[i])
	{
		if (!ft_isprint(s[i]))
			s[i] = '.';
		i++;
	}
	return (s);
}
