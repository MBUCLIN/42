/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_the_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 16:46:40 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 17:21:23 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				reverse_process_command(char *cmd)
{
	if (!ft_strcmp("ra", cmd))
		return (2);
	if (!ft_strcmp("rra", cmd))
		return (4);
	if (!ft_strcmp("sa", cmd))
		return (8);
	if (!ft_strcmp("pa", cmd))
		return (16);
	if (!ft_strcmp("pb", cmd))
		return (32);
	if (!ft_strcmp("rb", cmd))
		return (64);
	if (!ft_strcmp("rrb", cmd))
		return (128);
	if (!ft_strcmp("sb", cmd))
		return (256);
	if (!ft_strcmp("ss", cmd))
		return (512);
	if (!ft_strcmp("rr", cmd))
		return (1024);
	if (!ft_strcmp("rrr", cmd))
		return (2048);
	return (0);
}

static t_turn	*apply_action(t_turn *turn, int action)
{
	if (action == RR || action == RA)
		turn->a = rotate(turn->a);
	else if (action == RRR || action == RRA)
		turn->a = revrotate(turn->a);
	if (action == RR || action == RB)
		turn->b = rotate(turn->b);
	else if (action == RRR || action == RRB)
		turn->b = revrotate(turn->b);
	if (action == SS || action == SA)
		turn->a = swap(turn->a);
	if (action == SS || action == SB)
		turn->b = swap(turn->b);
	if (action == PA)
		turn = push(turn, 'a');
	else if (action == PB)
		turn = push(turn, 'b');
	return (turn);
}

t_turn			*make_the_action(t_turn *turn, char *cmd)
{
	int		act;

	act = reverse_process_command(cmd);
	return (apply_action(turn, act));
}
