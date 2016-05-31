/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 13:15:19 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/31 16:05:16 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int			goto_argpath(t_path *path, char *arg)
{
	char		*npath;

	if ((npath = ft_strjoin(path->cpath, "/")) == NULL)
		return (0);
	if ((npath = ft_strjoinfree(npath, arg)) == NULL)
		return (0);
	if (chdir(npath) == -1)
		return (-1);
	free(npath);
	return (1);
}

int			goto_lastpath(t_path *path)
{
	if (chdir(path->ppath) == -1)
		return (-1);
	return (1);
}

t_path		*goto_pathhome(char **env, t_path *path)
{
	char	*npath;

	if ((npath = ft_srchenv("HOME=", env)) == NULL)
		return (path);
	if ((chdir(npath)) == -1)
	{
		free(npath);
		return (path);
	}
	free(path->ppath);
	path->ppath = path->cpath;
	path->cpath = npath;
	return (path);
}

t_path		*goto_newpath(int n, t_path *path, char *arg)
{
	if (n == 1)
	{
		if ((n = goto_argpath(path, arg)) == -1)
			return (path);
		free(path->ppath);
		path->ppath = path->cpath;
		if (n == 0 || (path->cpath = getcwd(NULL, 0)) == NULL)
		{
			del_path(path);
			return (NULL);
		}
	}
	else
	{
		if ((n = goto_lastpath(path)) == -1)
			return (path);
		free(path->ppath);
		path->ppath = path->cpath;
		if ((path->cpath = getcwd(NULL, 0)) == NULL)
		{
			del_path(path);
			return (NULL);
		}
	}
	return (path);
}
