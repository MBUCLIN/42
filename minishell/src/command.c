/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:23:14 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/28 17:24:50 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int		find_command(t_shell **shell, char *command)
{
	char		*name;
	int			f;

	if ((name = get_commandname(command)) == NULL)
		return (-1);
	if ((f = search_envpath(name, shell)) == 0)
		return (0);
	else if (f == -1)
	{
		free(name);
		return (-1);
	}
	return (search_cpath(shell, name, (*shell)->path->cpath));
}

void		exec_command(t_shell *sh)
{
	int		father;
	int		stat;
	int		sig;

	if (check_exec(sh->exec->xpath) == -1)
	{
		ft_perror("minishell: command not found: ", sh->exec->xname);
		return ;
	}
	father = fork();
	if (father)
	{
		waitpid(father, &stat, 0);
		sig = WIFSIGNALED(stat);
		if (sig == SIGTSTP)
			signal(sig, &ft_kill);
		return ;
	}
	if (father == 0)
		execve(sh->exec->xpath, sh->exec->args, sh->env);
}
