/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:54:53 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/07 16:02:06 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

t_exec			*search_cpath(t_exec *exec, char *command)
{
	if (access(exec->xname, F_OK | X_OK) == -1 ||\
		ft_memchr(exec->xname, '/', 3) == NULL)
	{
		free(exec->xname);
		exec->xname = NULL;
		return (exec);
	}
	if ((exec->xpath = ft_strdup(exec->xname)) == NULL)
		end_minishell(-1);
	if ((exec->args = get_arguments(command)) == NULL)
		end_minishell(-1);
	return (exec);
}

char			*search_envpath(char *xname, t_shell *sh)
{
	char		*path;
	char		**paths;

	path = ft_srchenv("PATH", sh->env);
	if (path == NULL)
		return (NULL);
	if ((paths = ft_strsplit(path, ':')) == NULL)
		end_minishell(-1);
	path = NULL;
	if ((path = fnd_path(name, paths)) == NULL)
		end_minishell(-1);
	return (path);
}
