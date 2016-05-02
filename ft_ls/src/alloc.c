/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:24:22 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/27 18:44:42 by mbuclin          ###   ########.fr       */
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

t_all		*new_node_all(t_name *name, t_info *info)
{
	t_all		*new;

	new = NULL;
	if (!(new = (t_all *)malloc(sizeof(t_all))))
		return (NULL);
	new->next = NULL;
	new->name = name;
	new->info = info;
	return (new);
}
