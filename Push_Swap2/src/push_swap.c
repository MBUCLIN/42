/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 17:17:37 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 18:05:02 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int			get_closesnum_withrot(t_turn *turn, int max)
{
	t_pile	*tmp;

	tmp = turn->a;
	while (tmp->pos <= pile_len(turn->a) / 2 + 1)
	{
		if (condition_push_a(turn, tmp, max))
			return (tmp->pos);
		else if (condition_swap_a(turn, tmp, max))
			return (tmp->pos);
		else if (condition_push_b(turn, tmp, max))
			return (tmp->pos);
		tmp = tmp->next;
	}
	return (0);
}

static int			get_closesnum_withrev(t_turn *turn, int max)
{
	t_pile		*tmp;
	int			ret;
	int			change;

	tmp = turn->a;
	ret = 0;
	change = 0;
	while (tmp)
	{
		if (condition_push_a(turn, tmp, max))
			ret = tmp->pos;
		else if (condition_swap_a(turn, tmp, max))
			ret = tmp->pos;
		else if (condition_push_b(turn, tmp, max))
			ret = tmp->pos;
		tmp = tmp->next;
	}
	return (ret);
}

static int			choose_number(t_turn *turn)
{
	int			closebh;
	int			closeah;
	int			max;

	max = pile_len(turn->a) + pile_len(turn->b);
	closebh = get_closesnum_withrot(turn, max);
	closeah = get_closesnum_withrev(turn, max);
	if (!closeah && !closeah)
		return (0);
	if ((closeah != 0 && (pile_len(turn->a) - (closeah - 1) < closebh - 1)) ||\
		(closebh == 0 && closeah))
		return (closeah);
	return (closebh);
}

static int			choose_action(t_turn *turn, t_pile *tmp, int max)
{
	int			ret;

	ret = 0;
	if (condition_push_a(turn, tmp, max))
		ret = PA;
	else if (condition_swap_a(turn, tmp, max))
		ret = SA;
	else if (condition_push_b(turn, tmp, max))
		ret = PB;
	return (ret);
}

t_sop				*push_or_swap(t_turn *turn)
{
	t_sop		*ret;
	t_pile		*tmp;
	int			max;

	max = pile_len(turn->a) + pile_len(turn->b);
	if (!(ret = (t_sop *)malloc(sizeof(t_sop))))
		return (NULL);
	ret->toget = choose_number(turn);
	if (ret->toget == 0)
		return (ret);
	tmp = goto_pos(turn->a, ret->toget);
	ret->next = choose_action(turn, tmp, max);
	return (ret);
}
