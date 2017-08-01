/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 22:00:43 by avasseur          #+#    #+#             */
/*   Updated: 2015/06/26 14:10:00 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_continue_in_buf(char **line, char *cursor)
{
	char	*p1;
	char	*p2;
	char	*newline;

	p1 = ft_strcutdup(cursor, 1);
	ft_strdel(&cursor);
	newline = ft_strcjoin(*line, p1, '\n');
	free(*line);
	*line = ft_strdup(newline);
	free(newline);
	cursor = ft_strchr(p1, '\n');
	if (cursor)
	{
		p2 = ft_strcutdup(p1, ft_strlen(p1) - ft_strlen(cursor));
		cursor = NULL;
		return (p2);
	}
	free(p1);
	return (NULL);
}

static char	*ft_bufwork(char **line, char *buf, char *cursor)
{
	char	*cbuf;
	char	*newline;

	newline = ft_strcjoin(*line, buf, '\n');
	free(*line);
	*line = ft_strdup(newline);
	free(newline);
	cursor = ft_strchr(buf, '\n');
	if (cursor)
	{
		cbuf = ft_strdup(cursor);
		free(buf);
		cursor = cbuf;
	}
	if (!cursor)
		ft_strclr(buf);
	return (cursor);
}

int			ft_secure_read(int fd, char *buf)
{
	int		ret;

	ret = read(fd, buf, BUF_SIZE);
	if (ret == -1 || fd == -1 || BUF_SIZE <= 0 || ret == 0)
	{
		free(buf);
		if (ret == 0)
			return (0);
		return (-1);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*cursor;
	char			*buf;
	int				error;

	if (fd == -1 || BUF_SIZE <= 0 || !line)
		return (-1);
	*line = ft_memalloc(sizeof(char) * BUF_SIZE + 1);
	if (cursor)
	{
		cursor = ft_continue_in_buf(line, cursor);
		if (cursor)
			return (1);
	}
	buf = ft_memalloc(sizeof(char) * BUF_SIZE + 1);
	while (!cursor)
	{
		error = ft_secure_read(fd, buf);
		if (error == -1)
			return (-1);
		else if (error == 0)
			return (0);
		cursor = ft_bufwork(line, buf, cursor);
	}
	return (1);
}
