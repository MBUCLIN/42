/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 14:05:54 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 18:02:41 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		calcul_mediane(int max)
{
	if (max <= 100)
		return (max / 2);
	else if (max <= 1000)
		return (max / 10);
	return (max / 20);
}

t_turn			*push_b_mediane(t_turn *turn, int med)
{
	int		change;

	change = med;
	while (turn->a)
	{
		if (!(turn = push_med_b(turn, change)))
			return (NULL);
		change += med;
	}
	return (turn);
}

t_turn			*big_stack_algo(t_turn *turn, int max)
{
	int			mediane;
	t_turn		*tmp;

	mediane = calcul_mediane(max);
	if (!(tmp = push_b_mediane(turn, mediane)))
		return (del_turn(turn));
	turn = tmp;
	if (!(tmp = push_a_order(turn, max)))
		return (del_turn(turn));
	turn = tmp;
	if (!(tmp = rot_or_rev_to_order(turn, &turn->command)))
		return (del_turn(turn));
	turn = tmp;
	return (turn);
}
