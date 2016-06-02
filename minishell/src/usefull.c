/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 18:15:14 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/02 18:31:29 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

t_list		*new_arguments(t_list **head, char *content, size_t size)
{
	t_list		*new;

	if ((new = ft_lstnew(content, size)) == NULL)
		return (NULL);
	((char *)new->content)[new->content_size] = 0;
	ft_lstaddend(head, new);
	return (*head);
}

int			find_path(t_shell **sh, char *name, char **pathes)
{
	int		i;
	char	acc[256];
	int		len;

	i = 0;
	while (pathes[i])
	{
		len = fill_access(&acc, pathes[i], name);
		if (access(acc, F_OK) == 0)
		{
			if (((*sh)->exec = initiate_exec(pathes[i], name)) == NULL)
				return (-1);
			return (0);
		}
		else
			ft_memset(acc, 0, len);
		i++;
	}
	return (1);
}
