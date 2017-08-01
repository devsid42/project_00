/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 23:30:37 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/30 03:38:58 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wd_nb(const char *s, char c)
{
	int		word;
	int		i;

	if (!s)
		return (0);
	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if ((s[i] && s[i] != c) && (i == 0 || s[i - 1] == c))
			word++;
		i++;
	}
	return (word);
}

static char	**ft_split_proc(char c, char **ap, char *full, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*full != '\0')
	{
		if (*full != c)
		{
			if (j == 0)
			{
				if (!(ap[i] = ft_memalloc(sizeof(char) * len + 1)))
					return (NULL);
			}
			ap[i][j++] = *full;
		}
		else if (*full == c)
		{
			ap[i++][j] = '\0';
			j = 0;
		}
		full++;
	}
	return (ap);
}

char		**ft_strsplit(const char *s, char c)
{
	size_t		len;
	char		**ap;
	char		*full;
	int			nword;

	nword = ft_wd_nb(s, c);
	len = ft_strlen(s);
	if (!(ap = ft_memalloc(sizeof(*ap) * nword)))
		return (NULL);
	if (!s || !c)
		return (NULL);
	else if (ft_strocc(s, c) == len)
		return (ap);
	full = ft_strctrim(s, c);
	ap = ft_split_proc(c, ap, full, len);
	ap[nword] = malloc(sizeof(*ap) * 1);
	ap[nword] = 0;
	return (ap);
}
