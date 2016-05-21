/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:13:40 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/21 11:36:54 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_turn				*reset_pos(t_turn *head)
{
	t_pile		*tmp;
	int			pos;

	pos = 1;
	tmp = head->a;
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
	tmp = head->b;
	pos = 1;
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
	return (head);
}

int					check_sort(t_turn *node, int max)
{
	int		sort;
	t_pile	*tmp;

	sort = 0;
	tmp = node->a;
	while (tmp->next)
	{
		if (tmp->num < tmp->next->num)
			sort++;
		if (tmp->tmp == max)
			sort++;
		tmp = tmp->next;
	}
	if (tmp->num < node->a->num)
		sort++;
	if (tmp->tmp == max)
		sort++;
	return (sort);
}

t_turn				*little_stack_algo(t_turn *turn, int len)
{
	t_turn		*cpy;
	t_turn		*turnmp;
	t_cmd		*tmp;
	t_cmd		*tmpp;

	if (!(cpy = cpy_turn(turn)))
		return (del_turn(turn));
	if (!(turnmp = inteligent_sort(cpy)))
		return (del_turn(turn));
	cpy = turnmp;
	turnmp = NULL;
	if (!(turnmp = distance_sort(turn, len)))
		return (del_turn(cpy));
	tmp = last_cmd(cpy->command);
	tmpp = last_cmd(turn->command);
	if (tmp->turn < tmpp->turn)
	{
		turn = del_turn(turn);
		return (cpy);
	}
	cpy = del_turn(cpy);
	return (turn);
}

static t_turn		*choose_sort(t_turn *turn, char *option, int len)
{
	t_turn		*cpy;

	if (!(cpy = cpy_turn(turn)))
		return (del_turn(turn));
	else if (len <= 40)
	{
		if (!(cpy = little_stack_algo(cpy, len)))
			return (del_turn(turn));
	}
	else
	{
		if (!(cpy = big_stack_algo(cpy, len)))
			return (del_turn(turn));
	}
	turn->command = cpy->command;
	print_option_and_command(turn, option);
	del_command(turn->command);
	del_turn(cpy);
	return (turn);
}

t_turn				*init_sort(t_turn *head, char *option)
{
	int			sort;
	int			len;
	t_turn		*cpy;

	len = pile_len(head->a);
	head->a = init_tmp_and_pos(&head->a, len);
	sort = check_sort(head, len);
	if (!(cpy = cpy_turn(head)))
		return (del_turn(head));
	if (sort == len)
	{
		if (!(cpy = rot_or_rev_to_order(cpy, &cpy->command)))
			return (del_turn(head));
		head->command = cpy->command;
		print_option_and_command(head, option);
		del_command(head->command);
		del_turn(cpy);
	}
	else
	{
		if (!(cpy = choose_sort(cpy, option, len)))
			return (del_turn(head));
	}
	return (head);
}
