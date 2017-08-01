/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 14:50:45 by avasseur          #+#    #+#             */
/*   Updated: 2015/02/11 14:57:42 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlst;
	t_list	*tmp;

	nlst = NULL;
	if (lst && f)
	{
		tmp = f(lst);
		nlst = ft_lstnew(tmp->content, tmp->content_size);
		nlst->next = ft_lstmap(lst->next, f);
	}
	return (nlst);
}
