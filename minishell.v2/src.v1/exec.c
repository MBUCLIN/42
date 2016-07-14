/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:29:21 by mbuclin           #+#    #+#             */
/*   Updated: 2016/07/12 14:29:09 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int				is_exec(char *path)
{
	struct stat		buf;
	int				sta;

	sta = lstat(path, &buf);
	if (!sta && S_ISREG(buf.st_mode) && access(path, X_OK) == 0)
		return (sta);
	return (-1);
}

static void		signal_error(int pid, char *path, int sig)
{
	signal(sig, SIG_DFL);
	kill(sig, pid);
	msg_signal(sig, path);
}

void			exec_command(t_shell *sh)
{
	int			father;
	int			stat;

	stat = 0;
	if (is_exec(sh->exec->xpath))
	{
		ft_perror("minishell: command not found: ", ft_strdup(sh->exec->xpath));
		return ;
	}
	father = fork();
	if (father)
	{
		waitpid(father, &stat, 0);
		if (WIFSIGNALED(stat))
			signal_error(father, sh->exec->xname, stat);
	}
	if (!father)
		execve(sh->exec->xpath, sh->exec->args, sh->env);
	signal(SIGINT, ft_handle);
}
