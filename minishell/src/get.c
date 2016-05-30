/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:32:20 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/30 18:53:31 by mbuclin          ###   ########.fr       */
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
		if ((q == 0 || q % 2 == 0) && ft_isblank(command[i]) && i > st)
		{
			if ((new = ft_lstnew((command + st), i - st + 1)) == NULL)
				return (NULL);
			st += ft_skpblk((command + i)) + i;
			ft_lstaddend(&head, new);
		}
		i++;
	}
	if ((new = ft_lstnew((command + st), i - st)) == NULL)
		return (NULL);
	ft_lstaddend(&head, new);
	return (ft_lsttotabstrfree(head));
}

char		*get_var(char *arg, char **env)
{
	char		*var;
	char		*ret;

	if ((var = ft_strjoin(arg, "=")) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		end_minishell(NULL);
	}
	if ((ret = ft_srchenv(var, env)) == NULL)
		return (NULL);
	if ((ret = ft_strjoindfree(var, ret)) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		end_minishell(NULL);
	}
	return (ret);
}
