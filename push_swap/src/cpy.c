/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:47:05 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 13:50:36 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_pile		*new_node(t_pile *node)
{
	t_pile		*new;

	if (!(new = (t_pile *)malloc(sizeof(t_pile))))
		return (NULL);
	new->tmp = node->tmp;
	new->pos = node->pos;
	new->num = node->num;
	new->next = NULL;
	return (new);
}

static t_pile		*cpy_pile(t_pile *stack)
{
	t_pile		*tmp;
	t_pile		*cpy;
	t_pile		*tcpy;

	tmp = stack;
	if (!(cpy = new_node(tmp)))
		return (NULL);
	tcpy = cpy;
	while (tmp->next)
	{
		if (!(tcpy->next = new_node(tmp->next)))
			return (NULL);
		tcpy = tcpy->next;
		tmp = tmp->next;
	}
	return (cpy);
}

t_turn				*cpy_turn(t_turn *turn)
{
	t_turn		*cpy;

	if (!(cpy = (t_turn *)malloc(sizeof(t_turn))))
		return (NULL);
	if (!(cpy->a = cpy_pile(turn->a)))
		return (del_turn(cpy));
	cpy->b = NULL;
	cpy->command = NULL;
	cpy->moov = NULL;
	cpy->info = NULL;
	return (cpy);
}
