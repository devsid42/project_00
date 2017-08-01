/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itochex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 21:28:22 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/19 21:28:23 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_itochex(int n, char lower_upper)
{
	int	i;

	i = 10;
	while (i <= 15 && n >= 10 && n <= 15)
	{
		if (i == n && lower_upper == 'l')
			return (n + 'a' - 10);
		else if (i == n && lower_upper == 'U')
			return (n + 'A' - 10);
		i++;
	}
	return (n + '0');
}
