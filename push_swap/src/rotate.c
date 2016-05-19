/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 14:32:18 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 18:03:19 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				change_choice(int na, int nb, int choice)
{
	if (na <= 0 && nb <= 0)
		return (0);
	if (na <= 0)
	{
		if (choice == RR)
			return (RB);
		else if (choice == RRR)
			return (RRB);
	}
	if (nb <= 0)
	{
		if (choice == RR)
			return (RA);
		else if (choice == RRR)
			return (RRA);
	}
	return (0);
}

static int		choose_drot_or_brot(t_turn *head, t_pile *nodea)
{
	t_pile		*nodeb;

	nodeb = goto_tmp(head->b, nodea->tmp - 1);
	if (!nodeb || nodeb->pos == 1)
		return (0);
	if (nodea->pos != 1)
	{
		if (nodea->pos > (pile_len(head->a) / 2) + 1)
			return (RRR);
		else if (nodea->pos <= (pile_len(head->a) / 2) + 1)
			return (RR);
	}
	if (nodea->pos == 1 && nodeb->pos > pile_len(head->b) / 2 + 1)
		return (RRB);
	return (RB);
}

void			rotation(int cmd, t_turn *head)
{
	if (cmd == RA || cmd == RR)
		head->a = rotate(head->a);
	else if (cmd == RRA || cmd == RRR)
		head->a = revrotate(head->a);
	if (cmd == RB || cmd == RR)
		head->b = rotate(head->b);
	else if (cmd == RRB || cmd == RRR)
		head->b = revrotate(head->b);
}

static int		choose_rotation(t_turn *head, t_sop *sop)
{
	int			ret;
	t_pile		*tmp;

	ret = 0;
	if (sop->toget != 0)
		tmp = goto_pos(head->a, sop->toget);
	if (sop->next == PA && tmp)
		if ((ret = choose_drot_or_brot(head, tmp)))
			return (ret);
	if (sop->toget <= pile_len(head->a) / 2 + 1)
		return (RA);
	else if (sop->toget > pile_len(head->a) / 2 + 1)
		return (RRA);
	return (ret);
}

t_turn			*make_rotate_int(t_sop *sop, t_turn *head, t_cmd **cmd)
{
	int			choice;
	int			n;
	int			nb;

	nb = 0;
	n = 0;
	choice = choose_rotation(head, sop);
	if (choice == RA || choice == RR)
		n = sop->toget - 1;
	else if (choice == RRA || choice == RRR)
		n = pile_len(head->a) - sop->toget + 1;
	if (choice != RA && choice != RRA)
		nb = get_nnode(head, sop->toget, choice);
	while ((n > 0 || nb > 0) && choice)
	{
		rotation(choice, head);
		head = reset_pos(head);
		n--;
		nb--;
		if (!(*cmd = fill_list_command(cmd, choice)))
			return (del_turn(head));
		if ((nb == 0 || n == 0) && (choice == RR || choice == RRR))
			choice = change_choice(n, nb, choice);
	}
	return (head);
}
