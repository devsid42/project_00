/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:07:30 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:15:47 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(int n)
{
	if (n == ' ' || n == '\n' || n == '\t')
		return (1);
	else
		return (0);
}

static int	ft_count_ws(const char *s, int n)
{
	while (ft_iswhitespace(s[n]) > 0)
		n++;
	if (ft_strlen(s) == (size_t)n)
		return (-1);
	return (n);
}

char		*ft_strtrim(const char *s)
{
	int		i;
	int		y;
	int		z;
	char	*tmp;

	if (!s)
		return (NULL);
	i = 0;
	y = ft_strlen(s);
	i = ft_count_ws(s, i);
	while (ft_iswhitespace(s[y - 1]) > 0)
		y--;
	y -= i;
	if (i == -1)
		tmp = malloc(sizeof(tmp) * ft_strlen(s) + 1);
	else
		tmp = malloc(sizeof(tmp) * (y + 1));
	z = 0;
	while (z < y)
		tmp[z++] = s[i++];
	tmp[z] = '\0';
	return (tmp);
}
