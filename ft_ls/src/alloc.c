/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:24:22 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/02 15:08:42 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_name		*new_name(char *name, char *path)
{
	t_name		*new;

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

	if (!(new = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	if (stat(name->path, &buf))
		return (del_info(new));
	new->mode = buf.st_mode;
	new->time = get_time(buf, time);
	new->size = buf.st_size;
	new->hardl = buf.st_nlink;
	if (!(new->gr_name = get_group_name(buf.st_gid)))
		return (del_info(new));
	if (!(new->us_name = get_user_name(buf.st_uid)))
		return (del_info(new));
	return (new);
	
}

t_all		*new_node_all(t_name *name, t_info *info)
{
	t_all			*new;

	new = NULL;
	if (!(new = (t_all *)malloc(sizeof(t_all))))
		return (NULL);
	new->next = NULL;
	new->son = NULL;
	new->name = name;
	new->info = info;
	return (new);
}
