/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 12:43:10 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 17:37:33 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		print_info(t_inf *info)
{
	t_inf		*tmp;

	tmp = info;
	while (tmp)
	{
		ft_printf("%c	= stack\n", tmp->stack);
		ft_printf("%d	= num\n", tmp->n);
		ft_printf("%d	= distfrom\n", tmp->distfrom);
		ft_printf("%d	= dist\n", tmp->dist);
		ft_printf("%d	= distto\n", tmp->distto);
		ft_putendl("next info\n");
		tmp = tmp->next;
	}
}

void		print_moov(t_moov *moov)
{
	t_moov		*tmp;

	tmp = moov;
	while (tmp)
	{
		ft_printf("%c	= stack\n", tmp->stack);
		ft_printf("%d	= action\n", tmp->action);
		ft_printf("%d	= wayrot\n", tmp->wayrot);
		ft_printf("%d	= n_rot\n", tmp->n_rot);
		ft_printf("%d	= num\n", tmp->n);
		ft_putendl("next moov\n");
		tmp = tmp->next;
	}
}

void		put_tmp(t_pile *head)
{
	t_pile		*tmp;

	tmp = head;
	ft_putstr("Pile tmp =");
	while (tmp)
	{
		ft_printf(" %d", tmp->tmp);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void		put_pos(t_pile *head)
{
	t_pile		*tmp;

	tmp = head;
	ft_putstr("Pile pos =");
	while (tmp)
	{
		ft_printf(" %d", tmp->pos);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
