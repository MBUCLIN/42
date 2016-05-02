/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:09:38 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 18:09:53 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void				*del_info(t_inf *info)
{
	t_inf	*tmp;

	while (info)
	{
		tmp = info;
		info = info->next;
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

static t_inf		*finish_info(t_turn *turn, t_inf *nodei)
{
	nodei->dist = nodei->n - count_low(turn->b, nodei->n);
	nodei->distto = count_distfrom_n(turn, nodei);
	return (nodei);
}

static t_inf		*set_info(t_inf *info)
{
	info->stack = 0;
	info->n = 0;
	info->distfrom = 0;
	info->dist = 0;
	info->distto = 0;
	info->next = NULL;
	return (info);
}

t_inf				*get_info_b(t_turn *turn, int max)
{
	t_inf		*info;
	t_inf		*infmp;
	t_pile		*tmp;

	tmp = turn->b;
	if (!(info = (t_inf *)malloc(sizeof(t_inf))))
		return (NULL);
	if (!(tmp))
		return (set_info(info));
	infmp = info;
	while (tmp)
	{
		infmp->stack = 'B';
		infmp->n = tmp->tmp;
		infmp->distfrom = max;
		infmp = finish_info(turn, infmp);
		infmp->next = NULL;
		if (tmp->next)
			if (!(infmp->next = (t_inf *)malloc(sizeof(t_inf))))
				return (del_info(info));
		infmp = infmp->next;
		tmp = tmp->next;
	}
	return (info);
}

t_inf				*get_info_a(t_turn *turn, int max)
{
	t_inf		*info;
	t_inf		*infmp;
	t_pile		*tmp;

	tmp = turn->a;
	if (!(info = (t_inf *)malloc(sizeof(t_inf))))
		return (NULL);
	infmp = info;
	while (tmp)
	{
		infmp->stack = 'A';
		infmp->n = tmp->tmp;
		infmp->distfrom = max;
		infmp = finish_info(turn, infmp);
		infmp->next = NULL;
		if (tmp->next)
			if (!(infmp->next = (t_inf *)malloc(sizeof(t_inf))))
				return (del_info(info));
		infmp = infmp->next;
		tmp = tmp->next;
	}
	return (info);
}
