/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:46:21 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/12 17:50:21 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_all		*read_dir(t_all *node, DIR *dir, int option)
{
	struct dirent		*dirent;
	char				*path;
	t_all				*head;
	t_all				*tmp;

	head = NULL;
	while ((dirent = readdir(dir)))
	{
		if (!(path = create_path(node->name->path, dirent->d_name)))
			return (del_all(head));
		if (!(tmp =\
			new_node_all(new_name(dirent->d_name, path), option)))
			return (del_all(head));
		free(path);
		path = NULL;
		if (tmp->info->mode == 0)
		{
			del_all(head);
			return (tmp);
		}
		if (!(head))
			head = tmp;
		head = import(head, tmp, option);
	}
	return (head);
}

int			get_dir_content(t_all **node, int option)
{
	DIR		*dir;

	dir = NULL;
	if (!(dir = opendir((*node)->name->path)))
	{
		perror((*node)->name->path);
		return (-1);
	}
	if (!((*node)->son = read_dir(*node, dir, option)))
		return (0);
	if (closedir(dir))
		return (0);
	dir = NULL;
	if ((*node)->son->info->mode == 0)
		return (-1);
	ft_printf("%s:\n", (*node)->name->path);
	return (1);
}

t_all		*read_dir_arg(t_all *head, int option)
{
	t_all			*tmp;
	int				content;

	tmp = head;
	while (tmp)
	{
		if (!(content = get_dir_content(&tmp, option)))
			return (del_all(head));
		else if (content == 1)
		{
			if (!(tmp->son =\
				print_dir(tmp->son, get_len_max(tmp->son), option)))
				return (del_all(head));
			ft_putendl("");
			tmp->son = del_all(tmp->son);
		}
		tmp = tmp->next;
	}
	return (head);
}

t_all		*recursive(t_all *head, int option, int call)
{
	int			content;
	t_all		*tmp;

	tmp = head;
	while (tmp)
	{
		if (check_dir(tmp, option, call))
		{
			if (!(content = get_dir_content(&tmp, option)))
				return (del_all(head));
			if (content == 1)
			{
				if (!(tmp->son =\
					print_dir(tmp->son, get_len_max(tmp->son), option)))
					return (del_all(head));
				ft_putendl("");
				if (!(tmp->son = recursive(tmp->son, option, call + 1)))
					return (del_all(head));
				tmp->son = del_all(tmp->son);
			}
		}
		tmp = tmp->next;
	}
	return (head);
}
