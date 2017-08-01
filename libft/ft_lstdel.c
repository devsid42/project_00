/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 22:10:52 by avasseur          #+#    #+#             */
/*   Updated: 2015/01/22 17:10:34 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nlst;

	if (alst && del)
	{
		lst = *alst;
		while (lst)
		{
			nlst = lst->next;
			del(lst->content, lst->content_size);
			lst = nlst;
			free(nlst);
		}
		*alst = NULL;
	}
}
