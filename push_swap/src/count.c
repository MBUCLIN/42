/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 13:35:32 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 18:05:13 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			count_low(t_pile *head, int num)
{
	t_pile		*tmp;
	int			n_lower;

	tmp = head;
	n_lower = 0;
	while (tmp)
	{
		if (tmp->tmp < num)
			n_lower++;
		tmp = tmp->next;
	}
	return (n_lower);
}

int			count_distfrom_n(t_turn *turn, t_inf *inf)
{
	t_pile		*tmp;
	int			dist;

	if ((check_stack(turn->b, inf->n)))
		return (-1);
	dist = 0;
	tmp = goto_tmp(turn->a, inf->distfrom);
	if (tmp)
		while (tmp->tmp != inf->n)
		{
			dist++;
			if (tmp->next)
				tmp = tmp->next;
			else
				tmp = turn->a;
		}
	return (dist);
}

int			count_nrot_pb(t_pile *stack, t_inf *inf)
{
	int		ra;
	int		rra;
	t_pile	*tmp;

	tmp = stack;
	if (inf->dist == inf->distto || inf->n == 9)
		return (0);
	while (tmp)
	{
		if (tmp->tmp == inf->n)
		{
			ra = tmp->pos - 1;
			rra = 0;
		}
		tmp = tmp->next;
		rra++;
	}
	if (ra < rra)
		return (ra);
	return (rra);
}

int			count_rot_stack(t_pile *stack, t_moov *moov)
{
	int		len;
	int		pos;

	if (moov->stack != 'B')
		return (0);
	len = pile_len(stack);
	pos = get_pos(stack, moov->n);
	if (moov->wayrot == RA)
		return (pos - 1);
	else if (moov->wayrot == RRA && pos != 1)
		return ((len - pos) + 1);
	return (0);
}
