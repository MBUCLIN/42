/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:23:14 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/31 17:10:10 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int			find_command(t_shell **shell, char *command)
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
	char	*exec;

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
		waitpid(father, &stat, 0);
	if (!father)
		execve(exec, sh->exec->args, sh->env);
	free(exec);
}
