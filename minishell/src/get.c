/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:32:20 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/28 17:43:41 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

char		*get_commandname(char *command)
{
	int		sub;
	int		i;

	sub = 0;
	i = 0;
	while (command[i] && ft_isblank(command[i]))
		i++;
	while (command[i + sub] && command[i + sub] != ' ')
		sub++;
	return (ft_strsub(command, i, sub));
}

char		*get_linecommand(char *line)
{
	char		*afterpart;

	afterpart = NULL;
	if (line)
	{
		if (get_next_line(0, &afterpart) <= 0)
		{
			free(line);
			return (NULL);
		}
		if ((line = ft_strjoindfree(line, "\n")) == NULL)
			return (NULL);
		if ((line = ft_strjoindfree(line, afterpart)) == NULL)
			return (NULL);
	}
	else if (line == NULL)
		if (get_next_line(0, &line) <= 0)
			return (NULL);
	return (line);
}


char		**get_arguments(char *command)
{
	t_list		*head;
	t_list		*new;
	int			st;
	int			i;
	int			q;

	head = NULL;
	i = ft_skpblk(command);
	st = i;
	q = 0;
	while (command[i])
	{
		if (command[i] == '"')
			q++;
		if ((q == 0 || q % 2 == 0) && ft_isblank(command[i]))
		{
			if ((new = ft_lstnew((command + st), st - i + 1)) == NULL)
				return (NULL);
			((char *)new->content)[new->content_size] = 0;
			st = i + 1;
			ft_lstaddend(&head, new);
		}
		i++;
	}
	return (ft_lsttotabstrfree(head));
}

char		*get_fullpath(char *path, char *arg)
{
	char		*new;

	if (check_cut(arg) == -1)
		return (cut_path(path, arg));
	return (add_path(path, arg));
}
