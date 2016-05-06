/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:24:22 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/04 17:07:02 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*create_path(char *last_path, char *name)
{
	char	*path;

	path = NULL;
	if (!(path = ft_strjoin(last_path, "/")))
		return (NULL);
	if (!(path = ft_strjoindfree(path, ft_strdup(name))))
		return (NULL);
	return (path);
}

t_name		*new_name(char *name, char *path)
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

t_info		*new_info(t_name *name, int time)
{
	t_info			*new;
	struct stat		buf;

	new = NULL;
	if (!(new = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	new->gr_name = NULL;
	new->us_name = NULL;
	if (stat(name->path, &buf))
	{
		perror(name->name);
		return (del_info(new));
	}
	new->mode = buf.st_mode;
	new->time = get_time(buf, time, 0);
	new->ntime = get_time(buf, time, 1);
	new->size = buf.st_size;
	new->maj = need_major(buf, new->mode);
	new->min = need_minor(buf, new->mode);
	new->hardl = buf.st_nlink;
	if (!(new->gr_name = get_group_name(buf.st_gid)))
		return (del_info(new));
	if (!(new->us_name = get_user_name(buf.st_uid)))
		return (del_info(new));
	return (new);
}

t_all		*new_node_all(t_name *name, int option)
{
	t_all			*new;
	int				time;

	new = NULL;
	time = check_times_option(option);
	if (!(new = (t_all *)malloc(sizeof(t_all))))
		return (NULL);
	new->next = NULL;
	new->son = NULL;
	new->name = name;
	new->info = new_info(name, time);
	return (new);
}
