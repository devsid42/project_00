/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epurstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 01:40:01 by avasseur          #+#    #+#             */
/*   Updated: 2015/06/26 23:36:24 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_bad(char c)
{
	if (c == ' ' || c == '\t' || !ft_isprint(c))
		return (1);
	return (0);
}

static void	ft_init_ep(char **dup, char **clean)
{
	*dup = NULL;
	*clean = NULL;
}

char		*ft_epurstr(char *s)
{
	int		i;
	char	*dup;
	char	*clean;

	if (!s)
		return (NULL);
	ft_init_ep(&dup, &clean);
	i = 0;
	if (!(dup = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s && *s)
	{
		while (*s && ft_bad(*s) == 1)
			s++;
		while (*s && ft_bad(*s) == 0)
			dup[i++] = *s++;
		while (*s && ft_bad(*s) == 1)
			s++;
		if (*s)
			dup[i++] = ' ';
	}
	clean = ft_strdup(dup);
	free(dup);
	return (clean);
}
