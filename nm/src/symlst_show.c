/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symlst_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avasseur <avasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:01:30 by avasseur          #+#    #+#             */
/*   Updated: 2017/04/21 09:15:50 by avasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static size_t	ft_sizehexlen(size_t n)
{
	size_t	len;

	if (n < 16)
		return (1);
	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void		fill_output(char c, uint64_t origin_nbr, size_t max_len)
{
	size_t	i;

	i = 0;
	while (i < max_len - ft_sizehexlen(origin_nbr))
	{
		ft_putchar(c);
		i += 1;
	}
}

static void		put_option(t_env *e, t_symlst *lst)
{
	if (e->x_opt)
	{
		fill_output('0', lst->nsect & 0xff, 2);
		ft_printf(1, "%x ", lst->nsect & 0xff);
		fill_output('0', lst->desc & 0xffff, 4);
		ft_printf(1, "%x ", lst->desc & 0xffff);
		fill_output('0', *lst->symtab, 8);
		ft_printf(1, "%x ", *lst->symtab);
	}
}

static void		put_offset(t_env *e, t_symlst *lst)
{
	char	c;
	int		len_32_64;

	len_32_64 = 16;
	if (e->is_32 == 1)
		len_32_64 = 8;
	c = '0';
	if (lst->type_letter == 'U' && !e->x_opt)
		c = ' ';
	fill_output(c, lst->addr, len_32_64);
	if (lst->addr > 0 || e->x_opt)
		ft_printf(1, "%x ", lst->addr);
	else if (lst->addr == 0 && c == '0')
		ft_printf(1, "%x ", lst->addr);
	else
		ft_putstr("  ");
}

void			symlst_show(t_env *e, t_symlst *symlst)
{
	t_symlst	*lst;

	if (!symlst)
	{
		if (e->verbose > 0)
			ft_printf(2, "No Symbol\n");
		return ;
	}
	lst = symlst;
	while (lst)
	{
		put_offset(e, lst);
		if (e->x_opt > 0)
		{
			fill_output('0', lst->type & 0xff, 2);
			ft_printf(1, "%x ", lst->type & 0xff);
		}
		if (e->x_opt != 1)
			ft_printf(1, "%c ", lst->type_letter);
		put_option(e, lst);
		ft_printf(1, "%s\n", lst->name);
		lst = lst->next;
	}
}
