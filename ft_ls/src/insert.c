/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:12:12 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/13 11:41:47 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_all		*insert(t_all *head, t_all *new, t_all *node)
{
	t_all		*tmp;

	tmp = head;
	if (tmp == node)
	{
		new->next = head;
		return (new);
	}
	while (tmp->next != node)
		tmp = tmp->next;
	tmp->next = new;
	new->next = node;
	return (head);
}

t_all		*import_from_else(t_all *head, t_all *new, t_all *node, int opt)
{
	int		ntt;
	int		ntn;

	ntn = new->info->ntime;
	ntt = node->info->ntime;
	if ((ntn > ntt && !(opt & OPT_R)) || (ntn < ntt && (opt & OPT_R)))
		return (insert(head, new, node));
	else if (ntn == ntt)
	{
		if ((!ft_islexisort(new->name->name, node->name->name) &&\
			!(opt & OPT_R)) ||\
			(!ft_isrevlexisort(new->name->name, node->name->name) &&\
			(opt & OPT_R)))
			return (insert(head, new, node));
	}
	new->next = node->next;
	node->next = new;
	return (head);
}

t_all		*import_from_time(t_all *head, t_all *node, int option)
{
	t_all		*tmp;
	int			tt;
	int			tn;

	tmp = head;
	while (tmp)
	{
		tn = node->info->time;
		tt = tmp->info->time;
		if ((tn > tt && !(option & OPT_R)) || (tn < tt && (option & OPT_R)))
			return (insert(head, node, tmp));
		else if (tn == tt)
			return (import_from_else(head, node, tmp, option));
		tmp = tmp->next;
	}
	tmp = last_node(head);
	tmp->next = node;
	node->next = NULL;
	return (head);
}

t_all		*import(t_all *head, t_all *node, int option)
{
	t_all		*tmp;

	if (node == head)
		return (head);
	if (option & OPT_T && !(option & OPT_MU))
		return (import_from_time(head, node, option));
	tmp = head;
	while (tmp)
	{
		if ((!(ft_islexisort(node->name->name, tmp->name->name)) &&\
			(option ^ OPT_R)) ||\
			(!ft_isrevlexisort(node->name->name, tmp->name->name) &&\
			(option & OPT_R)))
		{
			head = insert(head, node, tmp);
			return (head);
		}
		tmp = tmp->next;
	}
	tmp = last_node(head);
	tmp->next = node;
	node->next = NULL;
	return (head);
}
