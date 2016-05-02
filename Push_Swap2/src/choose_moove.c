/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_moove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 13:41:01 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 14:03:54 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_moov		*choose_node_moov(t_moov *moov, int last)
{
	t_moov		*tmp;
	int			n_moov;
	int			n_nextmoov;
	t_moov		*node;

	tmp = moov;
	n_moov = 0;
	while (tmp)
	{
		if (tmp->action)
			n_nextmoov = 1 + tmp->n_rot;
		else
			n_nextmoov = 0;
		if (n_nextmoov == 1 && tmp->n == last)
			n_nextmoov = 0;
		if (n_nextmoov)
			if (n_nextmoov < n_moov || n_moov == 0)
			{
				n_moov = n_nextmoov;
				node = tmp;
			}
		tmp = tmp->next;
	}
	return (node);
}

t_turn		*choose_moov(t_turn *turn, int last)
{
	t_moov		*tmp;
	t_moov		*node;

	turn->info = del_info(turn->info);
	node = choose_node_moov(turn->moov, last);
	tmp = turn->moov;
	while (turn->moov != node)
	{
		turn->moov = turn->moov->next;
		free(tmp);
		tmp = turn->moov;
	}
	turn->moov->next = del_moov(tmp->next);
	return (turn);
}
