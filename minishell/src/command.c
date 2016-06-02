/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:23:14 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/02 18:44:01 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int				find_command(t_shell **shell, char *command)
{
	char		*name;
	int			f;

	if ((name = get_commandname(command)) == NULL)
		return (-1);
	if ((f = search_envpath(name, shell)) == 0)
		return (0);
	else if (f == -1)
		return (-1);
	if (ft_memchr(name, '/', 3) || check_builtin(name) == 0)
		return (search_cpath(shell, name));
	else
	{
		ft_perror("minishell: command not found: ", name);
		return (-2);
	}
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
