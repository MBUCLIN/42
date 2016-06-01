/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:23:14 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/01 16:21:37 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int				find_command(t_shell **shell, char *command)
{
	char		*name;
	int			f;

	if ((name = get_commandname(command)) == NULL)
		return (-1);
	ft_printf("|%s| : Xname\n", name);
	if ((f = search_envpath(name, shell)) == 0)
		return (0);
	else if (f == -1)
		return (-1);
	ft_printf("cpath : |%s|\n", (*shell)->path->cpath);
	return (search_cpath(shell, name, (*shell)->path->cpath));
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
	ft_printf("%d : sig\n", sig);
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
	ft_printf("len : %d\n", ft_tabstrlen(sh->exec->args));
	father = fork();
	if (father)
	{
		signal_controlc(father);
		waitpid(father, &stat, 0);
		signal_error(father, sh->exec->xname, stat);
	}
	if (!father)
	{
		execve(exec, sh->exec->args, sh->env);
	}
	signal(SIGINT, SIG_DFL);
	signal(SIGSEGV, SIG_DFL);
	free(exec);
}
