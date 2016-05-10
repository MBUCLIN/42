/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:24:32 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/10 12:13:55 by mbuclin          ###   ########.fr       */
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

void		*del_only_file(t_all *head, int opt)
{
	t_all		*del;
	t_all		*tmp;

	if (!head)
		return (NULL);
	del = head->next;
	if (!(check_dir(head, opt)))
	{
		del_all(head);
		return (del_only_file(del, opt));
	}
	tmp = head;
	while (del)
	{
		if (!check_dir(del, opt))
		{
			tmp->next = del->next;
			del_all(del);
			del = NULL;
		}
		tmp = tmp->next;
		if (tmp)
			del = tmp->next;
	}
	return (head);
}
