/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:09:31 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 18:03:00 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int			change_wayrot(int wayrot)
{
	if (wayrot == RA)
		return (RR);
	else if (wayrot == RRA)
		return (RRR);
	return (wayrot);
}

t_turn				*make_rotate(t_turn *turn)
{
	int		nb;
	int		n;
	int		wayrot;

	n = turn->moov->n_rot;
	wayrot = turn->moov->wayrot;
	nb = count_rot_stack(turn->b, turn->moov);
	if (!n && !nb)
		return (turn);
	if (nb)
		wayrot = change_wayrot(wayrot);
	while (n > 0 || nb > 0)
	{
		rotation(wayrot, turn);
		turn = reset_pos(turn);
		n--;
		nb--;
		if (!(turn->command = fill_list_command(&turn->command, wayrot)))
			return (del_turn(turn));
		if ((!nb || !n) && (wayrot == RR || wayrot == RRR))
			wayrot = change_choice(n, nb, wayrot);
	}
	return (turn);
}

t_turn				*make_moov(t_turn *turn, int action)
{
	if (action == PA)
		turn = push(turn, 'a');
	else if (action == PB)
		turn = push(turn, 'b');
	else if (action == SA)
		turn->a = swap(turn->a);
	turn = reset_pos(turn);
	if (!(turn->command = fill_list_command(&turn->command, action)))
		return (del_turn(turn));
	return (turn);
}
