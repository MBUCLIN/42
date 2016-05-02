/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:07:29 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 18:07:30 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		find_action(t_inf *inf)
{
	if (inf->n == 9)
		return (0);
	if (inf->distto == -1)
		return (PA);
	else if (inf->distto == inf->dist || inf->distto == 0)
		return (0);
	else if (inf->distto <= inf->dist + 1 && inf->distto >= inf->dist - 1)
		return (SA);
	return (PB);
}

void			*del_moov(t_moov *moov)
{
	t_moov		*tmp;

	tmp = moov;
	while (moov)
	{
		moov = moov->next;
		free(tmp);
		tmp = moov;
	}
	return (NULL);
}

t_moov			*treat_info(t_turn *turn)
{
	t_moov		*moov;
	t_inf		*tmp;
	t_moov		*moovmp;

	tmp = turn->info;
	if (!(moov = (t_moov *)malloc(sizeof(t_moov))))
		return (NULL);
	moovmp = moov;
	while (tmp)
	{
		moovmp->stack = tmp->stack;
		moovmp->action = find_action(tmp);
		moovmp->n_rot = search_n_rot(turn, tmp, moovmp->action);
		moovmp->wayrot = search_wayrot(turn, tmp, moovmp->action);
		moovmp->n = tmp->n;
		moovmp->next = NULL;
		if (tmp->next)
			if (!(moovmp->next = (t_moov *)malloc(sizeof(t_moov))))
				return (del_moov(moov));
		tmp = tmp->next;
		moovmp = moovmp->next;
	}
	return (moov);
}
