/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:46:21 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/02 17:50:18 by mbuclin          ###   ########.fr       */
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
			new_node_all(new_name(dirent->d_name, path), option, 0)))
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

int			get_dir_content(t_all **node, int option, int call)
{
	DIR		*dir;

	dir = NULL;
	if (call && (*node)->name->name[0] == '.' && !(option & OPT_A))
		return (-1);
	if (!(dir = opendir((*node)->name->path)))
	{
		if (!((*node)->printname))
			ft_printf("%s:\n", (*node)->name->path);
		ft_putendl("permi?");
		put_error((*node)->name->name);
		ft_putendl("mb?");
		if ((*node)->next)
			ft_putendl("");
		return (-1);
	}
	if (!((*node)->son = read_dir(*node, dir, option)))
		return (0);
	closedir(dir);
	if (!((*node)->printname))
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
		if (!(content = get_dir_content(&tmp, option, 0)))
			return (del_all(head));
		if (content == 1)
		{
			if (!(tmp->son =\
				print_dir(tmp->son, get_len_max(tmp->son), option)))
				return (del_all(head));
			if (tmp->next)
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
			if (!(content = get_dir_content(&tmp, option, call)))
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
