/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:04:55 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/04 17:31:57 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int			swap_node(t_all *head, t_all *node)
{
	t_all		*tmp;

	if (node != head)
	{
		tmp = head;
		while (tmp->next != node)
			tmp = tmp->next;
		tmp->next = node->next;
		node->next = node->next->next;
		tmp->next->next = node;
	}
	else
	{
		tmp = head->next;
		head->next = tmp->next;
		tmp->next = head;
		head = tmp;
	}
	return (1);
}

static t_all		*sort_by_time(t_all *all)
{
	t_all	*tmp;
	int		i;

	i = 1;
	while (i)
	{
		i = 0;
		tmp = all;
		while (tmp->next)
		{
			if (tmp->info->time < tmp->next->info->time)
			{
				print_all(all);
				ft_putendl("SWAPING");
				i += swap_node(all, tmp);
			}
			else if (tmp->info->time == tmp->next->info->time)
			{
				if (tmp->info->ntime < tmp->next->info->ntime)
					i+= swap_node(all, tmp);
				else if (tmp->info->ntime == tmp->next->info->ntime)
				{
					if (!ft_islexisort(tmp->name->name, tmp->next->name->name))
						i+= swap_node(all, tmp);
				}
			}
			tmp = tmp->next;
		}
	}
	return (all);
}

t_all				*sort_list(t_all *all, int option)
{
	t_all	*tmp;
	int		i;

	i = 1;
	if (option & OPT_T)
		return (sort_by_time(all));
	ft_putendl("YOLO");
	while (i)
	{
		i = 0;
		tmp = all;
		while (tmp->next)
		{
			ft_putendl("islexisort");
			ft_putendl(tmp->name->name);
			ft_putendl(tmp->next->name->name);
			if (ft_islexisort(tmp->name->name, tmp->next->name->name))
			{
				ft_putendl("swap");
				i += swap_node(all, tmp);
				ft_putendl("swap done");
			}
			tmp = tmp->next;
		}
		ft_printf("%d : i\n", i);
	}
	ft_putendl("YOLO");
	return (all);
}
