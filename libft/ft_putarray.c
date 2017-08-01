/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 19:14:25 by avasseur          #+#    #+#             */
/*   Updated: 2015/03/31 00:29:43 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarray(char **ap, const char *separator)
{
	int		i;

	if (ap)
	{
		i = 0;
		while (ap[i] != '\0')
		{
			ft_putstr(ap[i]);
			ft_putstr(separator);
			i++;
		}
	}
}
