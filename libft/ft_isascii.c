/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:02:57 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:08:18 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isascii(int n)
{
	if (n >= 0 && n <= 127)
		return (1);
	return (0);
}
