/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:06:38 by avasseur          #+#    #+#             */
/*   Updated: 2015/02/04 21:13:44 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	int		i;
	int		len;
	char	*tmp;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	tmp = ft_memalloc(sizeof(tmp) * len + 1);
	while (len--)
	{
		tmp[i] = s[len];
		i++;
	}
	return (tmp);
}
