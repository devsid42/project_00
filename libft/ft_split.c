/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 23:41:28 by avasseur          #+#    #+#             */
/*   Updated: 2017/03/01 16:20:25 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_badchar(char *spliter, char c)
{
	while (spliter && *spliter)
	{
		if (c == *spliter)
			return (1);
		spliter++;
	}
	return (0);
}

static int	ft_cnt_wd(char *s, char *spliter)
{
	int		is;
	int		word;

	is = 0;
	word = 0;
	while (s && *s && ft_badchar(spliter, *s))
		s++;
	while (s && *s)
	{
		while (*s && ft_badchar(spliter, *s) == 0)
		{
			is = 1;
			s++;
		}
		if (is == 1)
		{
			word++;
			is = 0;
		}
		while (*s && ft_badchar(spliter, *s))
			s++;
	}
	return (word);
}

static char	**ft_start_split(char *s, char *spltr)
{
	char	**a;

	a = NULL;
	if (!s || !*s || ft_cnt_wd(s, spltr) == 0)
		return (NULL);
	if (!(a = (char **)ft_memalloc(sizeof(char *) * (ft_cnt_wd(s, spltr) + 1))))
		return (NULL);
	a[ft_cnt_wd(s, spltr)] = NULL;
	if (!(a[0] = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		free(a);
		return (NULL);
	}
	return (a);
}

static void	ft_new_tab_split(char **a, int *i, int *j, char *s)
{
	a[*i][*j] = 0;
	*j = 0;
	(*i)++;
	a[*i] = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
}

char		**ft_split(char *s, char *spliter)
{
	char	**a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(a = ft_start_split(s, spliter)))
		return (NULL);
	while (s && *s && ft_badchar(spliter, *s))
		s++;
	while (s && *s)
	{
		while (s && *s && ft_badchar(spliter, *s) == 0)
			a[i][j++] = *s++;
		while (s && *s && ft_badchar(spliter, *s))
			s++;
		if (*s)
			ft_new_tab_split(a, &i, &j, s);
		else
			i++;
	}
	a[i] = NULL;
	return (a);
}
