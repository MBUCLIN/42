/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:24:22 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/12 16:18:04 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char				*create_path(char *last_path, char *name)
{
	char	*path;

	path = NULL;
	if (!(path = ft_strdup(last_path)))
		return (NULL);
	if (path[ft_strlen(path) - 1] != '/')
		if (!(path = ft_strjoindfree(path, ft_strdup("/"))))
			return (NULL);
	return (ft_strjoindfree(path, ft_strdup(name)));
}

t_name				*new_name(char *name, char *path)
{
	t_name		*new;

	new = NULL;
	if (!(new = (t_name *)malloc(sizeof(t_name))))
		return (NULL);
	if (!name)
		new->name = NULL;
	else if (!(new->name = ft_strdup(name)))
	{
		free(new);
		return (NULL);
	}
	if (!path)
		new->path = NULL;
	else if (!(new->path = ft_strdup(path)))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

static t_info		*set_info(t_info *new)
{
	new->mode = 0;
	new->time = 0;
	new->ntime = 0;
	new->size = 0;
	new->blck = 0;
	new->maj = 0;
	new->min = 0;
	new->hardl = 0;
	return (new);
}

t_info				*new_info(t_name *name, int time)
{
	t_info			*new;
	struct stat		buf;

	new = NULL;
	if (!(new = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	new->gr_name = NULL;
	new->us_name = NULL;
	if (lstat(name->path, &buf))
		return (set_info(new));
	new->mode = buf.st_mode;
	new->time = get_time(buf, time, 0);
	new->ntime = get_time(buf, time, 1);
	new->size = buf.st_size;
	new->blck = buf.st_blocks;
	new->maj = need_major(buf, new->mode);
	new->min = need_minor(buf, new->mode);
	new->hardl = buf.st_nlink;
	if (!(new->gr_name = get_group_name(buf.st_gid)))
		return (del_info(new));
	if (!(new->us_name = get_user_name(buf.st_uid)))
		return (del_info(new));
	return (new);
}

t_all				*new_node_all(t_name *name, int option)
{
	t_all			*new;
	int				time;

	new = NULL;
	time = check_times_option(option);
	if (!(new = (t_all *)malloc(sizeof(t_all))))
		return (NULL);
	new->next = NULL;
	new->son = NULL;
	if (!name)
	{
		del_name(name);
		return (del_all(new));
	}
	new->name = name;
	if (!(new->info = new_info(name, time)))
		return (del_all(new));
	return (new);
}
