/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 22:10:37 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/30 03:38:14 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strctrim_more(const char *s, char c)
{
	char		*tmp;
	size_t		i;
	int			y;

	i = 0;
	y = 0;
	if (!(tmp = ft_memalloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[0] == c && i == 0)
			i++;
		if (s[i] == c && i == ft_strlen(s) - 1)
		{
			tmp[y] = '\0';
			return (tmp);
		}
		tmp[y] = s[i];
		i++;
		y++;
	}
	tmp[y] = '\0';
	return (tmp);
}

char		*ft_strctrim(const char *s, char c)
{
	char	*tmp;
	int		i;
	int		y;

	if (!s)
		return (NULL);
	if (!(tmp = ft_memalloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	y = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] == c)
			i++;
		else
		{
			tmp[y] = s[i];
			i++;
			y++;
		}
	}
	tmp[y] = '\0';
	return (ft_strctrim_more(tmp, c));
}
