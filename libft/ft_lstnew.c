/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 19:02:11 by avasseur          #+#    #+#             */
/*   Updated: 2015/03/05 23:55:46 by xtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	if (!content)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->x = 0;
		return (tmp);
	}
	tmp->content = (void *)malloc(sizeof(tmp->content) * content_size);
	if (!tmp->content)
		return (NULL);
	tmp->content = ft_memcpy(tmp->content, content, content_size);
	tmp->content_size = content_size;
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->x = 0;
	return (tmp);
}
