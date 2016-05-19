/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:06:51 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 14:04:03 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_turn		*distance_sort(t_turn *turn, int max)
{
	int			last;

	while (max != check_sort(turn, max))
	{
		if (!(turn->info = search_info(turn, max)))
			return (del_turn(turn));
		if (!(turn->moov = treat_info(turn)))
			return (del_turn(turn));
		turn = choose_moov(turn, last);
		if (!(turn = make_rotate(turn)))
			return (NULL);
		if (!(turn = make_moov(turn, turn->moov->action)))
			return (NULL);
		last = turn->moov->n;
		turn->moov = del_moov(turn->moov);
	}
	if (!(turn = rot_or_rev_to_order(turn, &turn->command)))
		return (NULL);
	return (turn);
}
