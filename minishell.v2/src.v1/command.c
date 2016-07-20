/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:23:14 by mbuclin           #+#    #+#             */
/*   Updated: 2016/07/18 13:42:12 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

static int		isbuiltin(char *name)
{
	if (!ft_strcmp(name, "cd") || !ft_strcmp(name, "env") ||\
		!ft_strcmp(name, "setenv") || !ft_strcmp(name, "unsetenv") ||\
		!ft_strcmp(name, "exit") || !ft_strcmp(name, "echo"))
		return (1);
	return (0);
}

static char		*get_commandname(char *command)
{
	int		sub;
	int		i;

	sub = 0;
	i = ft_skpblk(command);
	while (command[i + sub] && command[i + sub] != ' ')
		sub++;
	return (ft_strsub(command, i, sub));
}

t_exec			*find_commandtype(t_shell *shell, char *command)
{
	t_exec		*exec;

	if ((exec = initiate_exec()) == NULL)
		end_minishell(-1);
	if ((exec->args = get_arguments(command, &exec->args)) == NULL)
		end_minishell(-1);
	if ((exec->xname = get_commandname(command)) == NULL)
		end_minishell(-1);
	if (ft_strlen(exec->xname) >= 256)
	{
		ft_perror("minishell: command too long: ", exec->xname);
		exec->xname = NULL;
		return (exec);
	}
	if (isbuiltin(exec->xname))
	{
		exec->xpath = NULL;
		return (exec);
	}
	if ((exec->xpath = search_envpath(exec->xname, shell)) == NULL)
		return (search_cpath(exec));
	return (exec);
}
