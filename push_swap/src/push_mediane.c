/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_mediane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 14:25:13 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 15:41:53 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_turn		*push_to_b(t_turn *turn, int pos)
{
	while (pos)
	{
		turn->a = rotate(turn->a);
		if (!(turn->command = fill_list_command(&turn->command, RA)))
			return (NULL);
		pos--;
	}
	turn = push(turn, 'b');
	if (!(turn->command = fill_list_command(&turn->command, PB)))
		return (NULL);
	return (turn);
}

t_turn		*push_med_b(t_turn *turn, int med)
{
	t_pile		*tmp;

	tmp = turn->a;
	while (tmp)
	{
		if (tmp->tmp <= med)
		{
			if (!(turn = push_to_b(turn, tmp->pos - 1)))
				return (NULL);
			tmp = turn->a;
			turn = reset_pos(turn);
		}
		else
			tmp = tmp->next;
	}
	return (turn);
}
