/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inteligent_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:35:43 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/25 14:17:51 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_turn		*apply_action(t_turn *turn, t_sop *sop, int len)
{
	if (sop->toget)
	{
		if (!(turn = make_rotate_int(sop, turn, &turn->command)))
			return (del_turn(turn));
		if (!(turn = make_action(turn, sop->next, &turn->command)))
			return (del_turn(turn));
		free(sop);
	}
	else
	{
		free(sop);
		return (distance_sort(turn, len));
	}
	return (turn);
}

t_turn				*inteligent_sort(t_turn *head)
{
	int		len;
	t_sop	*sop;
	int		check;

	sop = NULL;
	len = pile_len(head->a);
	while (len != (check = check_sort(head, len)) || head->b)
	{
		if (check == pile_len(head->a))
			return (push_stack_b_in_a(head, &head->command));
		sop = push_or_swap(head);
		if (!(head = apply_action(head, sop, len)))
			return (NULL);
		sop = NULL;
	}
	if (!(head = rot_or_rev_to_order(head, &head->command)))
		return (del_turn(head));
	return (head);
}
