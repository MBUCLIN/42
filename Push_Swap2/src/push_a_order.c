/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:06:39 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 18:08:29 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_turn		*push_to_a(t_turn *turn, int pos, int sens)
{
	int		len;

	len = pile_len(turn->b);
	while (pos <= len && pos)
	{
		if (sens == -1)
		{
			turn->b = rotate(turn->b);
			pos--;
			if (!(turn->command = fill_list_command(&turn->command, RB)))
				return (NULL);
		}
		else
		{
			turn->b = revrotate(turn->b);
			pos++;
			if (!(turn->command = fill_list_command(&turn->command, RRB)))
				return (NULL);
		}
	}
	turn = push(turn, 'a');
	if (!(turn->command = fill_list_command(&turn->command, PA)))
		return (NULL);
	turn = reset_pos(turn);
	return (turn);
}

t_turn		*push_n_a(t_turn *turn, int n)
{
	t_pile		*tmp;
	int			len;

	tmp = turn->b;
	len = pile_len(tmp);
	while (tmp)
	{
		if (tmp->tmp == n)
		{
			if (tmp->pos < len / 2 + 1)
				return (push_to_a(turn, tmp->pos - 1, -1));
			else
				return (push_to_a(turn, tmp->pos, 1));
		}
		tmp = tmp->next;
	}
	return (turn);
}

t_turn		*push_a_order(t_turn *turn, int max)
{
	int			n;

	n = max;
	while (turn->b)
	{
		if (!(turn = push_n_a(turn, n)))
			return (NULL);
		n--;
	}
	return (turn);
}
