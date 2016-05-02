/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:33:01 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 13:11:03 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			check_stack(t_pile *stack, int num)
{
	t_pile		*tmp;
	int			len;

	len = pile_len(stack);
	tmp = stack;
	if (!len)
		return (0);
	while (tmp)
	{
		if (tmp->tmp == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			check_before(t_pile *stack, int pos, int max, int n)
{
	t_pile		*tmp;

	tmp = goto_pos(stack, pos);
	if (pos == 0)
		pos = pile_len(stack);
	if ((tmp->next && (tmp->tmp + 1 == tmp->next->tmp ||\
		(tmp->tmp == max && tmp->next->tmp == 1))) || (!tmp->next &&\
		(tmp->tmp + 1 == stack->tmp || (tmp->tmp == max && stack->tmp == 1))))
	{
		if (n == pile_len(stack))
			return (n);
		else if (pos != 1)
			n = check_before(stack, pos - 1, max, n + 1);
		else
			n = check_before(stack, pile_len(stack), max, n + 1);
	}
	return (n);
}
