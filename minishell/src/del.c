/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:14:45 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/06 15:57:58 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void		del_path(t_path *path)
{
	if (path)
	{
		if (path->cpath)
		{
			free(path->cpath);
			path->cpath = NULL;
		}
		if (path->ppath)
		{
			free(path->ppath);
			path->ppath = NULL;
		}
		free(path);
	}
}

void		del_exec(t_exec *exec)
{
	if (exec)
	{
		if (exec->xpath)
		{
			free(exec->xpath);
			exec->xpath = NULL;
		}
		if (exec->xname)
		{
			free(exec->xname);
			exec->xname = NULL;
		}
		if (exec->args)
		{
			ft_putendl("EXEC args de mes couilles");
			exec->args = ft_deltabstr(exec->args, ft_tabstrlen(exec->args));
		}
		exec->xpid = -1;
		ft_putendl("EXEC TA MERE LA PUTE ");
		free(exec);
	}
}

void		del_shell(t_shell *shell)
{
	if (shell)
	{
		if (shell->path)
			del_path(shell->path);
		if (shell->exec)
			del_exec(shell->exec);
		if (shell->prompt)
		{
			free(shell->prompt);
			shell->prompt = NULL;
		}
		free(shell);
	}
}
