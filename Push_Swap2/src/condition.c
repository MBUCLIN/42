/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:49:08 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 18:10:42 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		condition_push_a(t_turn *head, t_pile *tmp, int max)
{
	int		check;

	check = tmp->tmp - 1;
	if (check == 0)
		check = max;
	if (check_stack(head->b, check))
		return (1);
	return (0);
}

int		condition_swap_a(t_turn *turn, t_pile *tmp, int max)
{
	if (tmp->next && tmp->next->next &&\
		((tmp->tmp + 1 == tmp->next->next->tmp &&\
		tmp->next->tmp != tmp->tmp + 2) ||\
		(tmp->tmp == max && tmp->next->next->tmp == 1 && tmp->next->tmp != 2)))
		return (1);
	if (tmp->next && (tmp->tmp - 1 == tmp->next->tmp ||\
		(tmp->tmp == 1 && tmp->next->tmp == max)))
		return (1);
	if (tmp->next && !tmp->next->next &&\
		((tmp->tmp + 1 == turn->a->tmp && tmp->next->tmp != tmp->tmp + 2) ||\
		(tmp->tmp == max && turn->a->tmp == 1 && tmp->next->tmp != 2)))
		return (1);
	if (!tmp->next && (tmp->tmp - 1 == turn->a->tmp ||\
		(tmp->tmp == 1 && turn->a->tmp == max)))
		return (1);
	if (!tmp->next && ((tmp->tmp + 1 == turn->a->next->tmp &&\
		turn->a->tmp != tmp->tmp + 2) ||\
		(tmp->tmp == 1 && turn->a->next->tmp == max && turn->a->tmp != 2)))
		return (1);
	return (0);
}

int		condition_push_b(t_turn *turn, t_pile *tmp, int max)
{
	if ((tmp->next && tmp->tmp == max && tmp->next->tmp == 1) ||\
		(!tmp->next && tmp->tmp == max && turn->a->tmp == 1))
		return (0);
	if ((tmp->tmp != max && check_stack(turn->b, tmp->tmp + 1)) ||\
		(tmp->tmp == max && check_stack(turn->b, 1)))
		return (0);
	if ((tmp->pos != 1 && check_before(turn->a, tmp->pos - 1, max, 0) > 2) ||\
		(tmp->pos == 1 && check_before(turn->a, pile_len(turn->a), max, 0) > 2))
		return (0);
	if (tmp->next && tmp->next->next &&\
		tmp->tmp + 1 != tmp->next->tmp &&\
		tmp->tmp + 1 != tmp->next->next->tmp && tmp->tmp != max)
		return (1);
	if (tmp->next && !tmp->next->next &&\
		tmp->tmp + 1 != tmp->next->tmp &&\
		tmp->tmp + 1 != turn->a->tmp && tmp->tmp != max)
		return (1);
	if (!tmp->next && tmp->tmp + 1 != turn->a->tmp &&\
		tmp->tmp + 1 != turn->a->next->tmp && tmp->tmp != max)
		return (1);
	return (0);
}
