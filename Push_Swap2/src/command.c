/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:09:13 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 16:56:33 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_turn		*push(t_turn *head, int c)
{
	t_pile		*tmp;

	if (c == 'a')
	{
		tmp = head->b->next;
		head->b->next = head->a;
		head->a = head->b;
		head->b = tmp;
	}
	else if (c == 'b')
	{
		tmp = head->a->next;
		head->a->next = head->b;
		head->b = head->a;
		head->a = tmp;
	}
	return (head);
}

t_pile		*swap(t_pile *swap)
{
	t_pile		*tmp;

	if (swap && swap->next)
	{
		tmp = swap->next;
		swap->next = tmp->next;
		tmp->next = NULL;
		tmp->next = swap;
		swap = tmp;
	}
	return (swap);
}

t_pile		*rotate(t_pile *rotate)
{
	t_pile		*tmp;
	t_pile		*tmps;

	if (rotate && rotate->next)
	{
		tmp = rotate;
		tmps = rotate->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = rotate;
		rotate->next = NULL;
		rotate = tmps;
	}
	return (rotate);
}

t_pile		*revrotate(t_pile *revrot)
{
	t_pile		*tmp;
	t_pile		*tmps;

	if (revrot && revrot->next)
	{
		tmp = revrot;
		tmps = revrot;
		while (tmp->next)
			tmp = tmp->next;
		while (tmps->next != tmp)
			tmps = tmps->next;
		tmp->next = revrot;
		tmps->next = NULL;
		revrot = tmp;
	}
	return (revrot);
}
