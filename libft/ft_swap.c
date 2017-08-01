/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 12:51:16 by avasseur          #+#    #+#             */
/*   Updated: 2017/03/10 12:52:37 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapc(char *c1, char *c2)
{
	char	c3;

	c3 = *c1;
	*c1 = *c2;
	*c2 = c3;
}

void	ft_swapi(int *n1, int *n2)
{
	int		n3;

	n3 = *n1;
	*n1 = *n2;
	*n2 = n3;
}

void	ft_swap_ptr(char **p1, char **p2)
{
	char	*p3;

	p3 = *p1;
	*p1 = *p2;
	*p2 = p3;
}
