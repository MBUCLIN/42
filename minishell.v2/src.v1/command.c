/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:23:14 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/07 16:05:52 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

static int		isbuiltin(char *name)
{
	if (!ft_strcmp(name, "cd") || !ft_strcmp(name, "env") ||\
		!ft_strcmp(name, "setenv") || !ft_strcmp(name, "unsetenv") ||\
		!ft_strcmp(name, "exit"))
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
	if ((exec->xname = get_commandname(command)) == NULL)
		end_minishell(-1);
	if (ft_strlen(exec->xname) >= 256)
	{
		free(exec->xname);
		exec->xname = NULL;
		return (exec);
	}
	if (isbuiltin(exec->xname))
	{
		if ((exec->args = get_arguments(command)) == NULL)
			end_minishell(-1);
		exec->path = NULL;
		return (exec);
	}
	if ((exec->xpath = search_envpath(exec->xname, shell)) == NULL)
		return (search_cpath(exec, command));
	if ((exec->args = get_arguments(command)) == NULL)
		end_minishell(-1);
	return (exec);
}

static void		signal_controlc(int father)
{
	if (signal(SIGINT, SIG_IGN))
	{
		kill(SIGINT, father);
		ft_putendl("");
		return ;
	}
}

static void		signal_error(int father, char *name, int sig)
{
	signal(sig, SIG_DFL);
	kill(sig, father);
	msg_signal(sig, name);
}

void			exec_command(t_shell *sh)
{
	int		father;
	int		stat;
	char	*exec;

	stat = 0;
	if ((exec = ft_creadir(sh->exec->xpath, sh->exec->xname)) == NULL)
		end_minishell(sh);
	if (check_exec(exec) == -1)
	{
		ft_perror("minishell: command not found: ", sh->exec->xname);
		return ;
	}
	father = fork();
	if (father)
	{
		signal_controlc(father);
		waitpid(father, &stat, 0);
		if (WIFSIGNALED(stat))
			signal_error(father, sh->exec->xname, stat);
	}
	if (!father)
		execve(exec, sh->exec->args, sh->env);
	signal(SIGINT, SIG_DFL);
	signal(SIGSEGV, SIG_DFL);
	free(exec);
}
