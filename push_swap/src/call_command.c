/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 15:40:34 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 18:10:27 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		need_rotate(t_turn *head, int rot)
{
	if (rot == RA)
		head->a = rotate(head->a);
	else
		head->a = revrotate(head->a);
}

t_turn			*rot_or_rev_to_order(t_turn *head, t_cmd **cmd)
{
	t_pile		*tmp;
	int			n;
	int			sens;

	sens = RRA;
	tmp = goto_minstack(head->a);
	if (tmp->pos <= pile_len(head->a) / 2 + 1)
	{
		sens = RA;
		n = tmp->pos - 1;
	}
	else
		n = pile_len(head->a) - (tmp->pos - 1);
	while (n > 0)
	{
		need_rotate(head, sens);
		head = reset_pos(head);
		n--;
		if (!(*cmd = fill_list_command(cmd, sens)))
			return (del_turn(head));
	}
	return (head);
}

t_turn			*push_stack_b_in_a(t_turn *head, t_cmd **cmd)
{
	t_sop		*sop;
	t_pile		*tmpa;
	t_pile		*tmpb;

	if (!(sop = (t_sop *)malloc(sizeof(t_sop))))
		return (NULL);
	sop->next = PA;
	tmpb = goto_minstack(head->b);
	if (!(tmpa = goto_tmp(head->a, tmpb->tmp + 1)))
		tmpa = head->a;
	sop->toget = tmpa->pos;
	if (!(head = make_rotate_int(sop, head, cmd)))
		return (NULL);
	free(sop);
	head = push(head, 'a');
	if (!(*cmd = fill_list_command(cmd, PA)))
		return (del_turn(head));
	head = reset_pos(head);
	if (!head->b)
		return (rot_or_rev_to_order(head, cmd));
	if (!(head = push_stack_b_in_a(head, cmd)))
		return (NULL);
	return (head);
}

t_turn			*make_action(t_turn *head, int act, t_cmd **cmd)
{
	if (act == PA)
		head = push(head, 'a');
	else if (act == PB)
		head = push(head, 'b');
	else if (act == SA)
		head->a = swap(head->a);
	head = reset_pos(head);
	if (!(*cmd = fill_list_command(cmd, act)))
		return (del_turn(head));
	return (head);
}
