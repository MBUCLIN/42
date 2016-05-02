/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:07:48 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 18:07:49 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				search_n_rot(t_turn *turn, t_inf *info, int action)
{
	int		pos;
	int		need_pos;
	int		dist;
	int		len;

	len = pile_len(turn->a);
	dist = info->dist;
	if (!action)
		return (0);
	if (action == PB)
		return (count_nrot_pb(turn->a, info));
	if ((action == SA && info->dist - 1 == info->distto))
		dist = info->dist - 1;
	pos = get_pos(turn->a, info->distfrom);
	need_pos = pos + dist;
	if (need_pos > len)
		need_pos -= len;
	if (need_pos <= len / 2 + 1)
		return (need_pos - 1);
	return ((len - need_pos) + 1);
}

static int		search_wayrot_pb(t_turn *turn, t_inf *inf)
{
	t_pile		*tmp;
	int			len;

	len = pile_len(turn->a);
	tmp = turn->a;
	while (tmp)
	{
		if (tmp->tmp == inf->n)
			break ;
		tmp = tmp->next;
	}
	if (tmp->pos <= len / 2 + 1)
		return (RA);
	return (RRA);
}

int				search_wayrot(t_turn *turn, t_inf *info, int action)
{
	int		pos;
	int		need_pos;
	int		dist;
	int		len;

	len = pile_len(turn->a);
	dist = info->dist;
	if (action == 0)
		return (0);
	if (action == PB)
		return (search_wayrot_pb(turn, info));
	if (action == SA && info->dist - 1 == info->distto)
		dist = info->distto;
	pos = get_pos(turn->a, info->distfrom);
	need_pos = pos + dist;
	if (need_pos > len)
		need_pos -= len;
	if (need_pos <= len / 2 + 1)
		return (RA);
	return (RRA);
}

t_inf			*search_info(t_turn *turn, int max)
{
	t_inf			*inf;
	t_inf			*tmp;

	inf = NULL;
	if (!(inf = get_info_a(turn, max)))
		return (NULL);
	tmp = goto_lastinfo(inf);
	if (!(tmp->next = get_info_b(turn, max)))
		return (del_info(inf));
	return (inf);
}
