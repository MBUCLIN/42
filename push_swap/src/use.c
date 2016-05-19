/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:45:16 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/21 16:34:29 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			pile_len(t_pile *head)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_pile		*goto_pos(t_pile *head, int pos)
{
	t_pile		*tmp;

	tmp = head;
	while (tmp && tmp->pos != pos)
		tmp = tmp->next;
	return (tmp);
}

t_pile		*goto_tmp(t_pile *head, int num)
{
	t_pile		*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->tmp == num)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_pile		*goto_minstack(t_pile *head)
{
	t_pile		*tmp;
	t_pile		*ret;

	tmp = head;
	ret = head;
	while (tmp)
	{
		if (tmp->tmp < ret->tmp)
			ret = tmp;
		tmp = tmp->next;
	}
	return (ret);
}

t_inf		*goto_lastinfo(t_inf *info)
{
	t_inf		*tmp;

	tmp = info;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
