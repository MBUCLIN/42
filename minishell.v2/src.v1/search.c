/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:54:53 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/08 15:09:03 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

t_exec			*search_cpath(t_exec *exec)
{
	if (access(exec->xname, F_OK | X_OK) == -1 ||\
		ft_memchr(exec->xname, '/', 3) == NULL)
	{
		ft_perror("minishell: command not found: ", exec->xname);
		exec->xname = NULL;
		return (exec);
	}
	if ((exec->xpath = ft_strdup(exec->xname)) == NULL)
		end_minishell(-1);
	return (exec);
}

static char		*find_path(char *name, char **paths)
{
	int		i;
	int		len;
	char	acc[256];

	i = 0;
	while (paths[i])
	{
		len = fill_access(&acc, paths[i], name);
		if (access(acc, F_OK) == 0)
			break ;
		else
			ft_memset(acc, 0, len);
		i++;
	}
	if (paths[i] == NULL)
		return (ft_strdup(""));
	return (ft_strdup(acc));
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
	if ((path = find_path(xname, paths)) == NULL)
		end_minishell(-1);
	if (!ft_strcmp(path, ""))
	{
		free(path);
		return (NULL);
	}
	return (path);
}
