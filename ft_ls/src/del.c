/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:24:32 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/03 17:09:19 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		*del_name(t_name *name)
{
	if (name)
	{
		if (name->name)
			free(name->name);
		if (name->path)
			free(name->path);
		free(name);
	}
	return (NULL);
}

void		*del_info(t_info *info)
{
	if (info)
	{
		if (info->gr_name)
			free(info->gr_name);
		if (info->us_name)
			free(info->us_name);
		free(info);
	}
	return (NULL);
}

void		*del_all(t_all *head)
{
	t_all		*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		if (tmp->name)
			del_name(tmp->name);
		if (tmp->info)
			del_info(tmp->info);
		if (tmp)
			free(tmp);
	}
	return (NULL);
}

void		*del_only_file(t_all *head)
{
	t_all		*del;
	t_all		*tmp;

	if (head->info->mode & 0100000)
	{
		del = head->next;
		free(head);
		head = del;
		return (del_only_file(head));
	}
	del = head->next;
	tmp = head;
	while (del)
	{
		if (del->info->mode & 0100000)
		{
			tmp->next = del->next;
			free(del);
		}
		tmp = tmp->next;
		del = tmp->next;
	}
	return (head);
}
