/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:54:53 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/06 15:05:55 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int		search_cpath(t_shell **shell, char *name)
{
	char	acc[256];
	int		len;

	if ((len = fill_access(&acc, NULL, name)) == -1)
	{
		free(name);
		ft_perror("minishell: command to long: ", name);
		return (-2);
	}
	if (access(acc, F_OK) == 0)
	{
		if (((*shell)->exec = initiate_exec(NULL, name)) == NULL)
		{
			free(name);
			return (-1);
		}
		return (0);
	}
	if ((((*shell)->exec) = initiate_exec(NULL, name)) == NULL)
	{
		free(name);
		return (-1);
	}
	return (1);
}

int		search_pathofname(t_shell **sh, char *xname, char **pathes)
{
	int		f;

	if (!ft_strcmp("cd", xname))
	{
		if (((*sh)->exec = initiate_exec(NULL, xname)) == NULL)
			return (-1);
		return (0);
	}
	if (ft_strlen(xname) > 253)
	{
		ft_deltabstr(pathes, ft_tabstrlen(pathes));
		return (1);
	}
	if ((f = find_path(sh, xname, pathes)) == -1)
	{
		ft_deltabstr(pathes, ft_tabstrlen(pathes));
		free(xname);
		return (-1);
	}
	ft_deltabstr(pathes, ft_tabstrlen(pathes));
	return (f);
}

int		search_envpath(char *xname, t_shell **sh)
{
	char		*path;
	char		**pathes;

	if ((path = ft_srchenv("PATH=", (*sh)->env)) == NULL)
		return (1);
	if ((pathes = ft_strsplit(path, ':')) == NULL)
	{
		free(path);
		return (-1);
	}
	free(path);
	return (search_pathofname(sh, xname, pathes));
}

int		search_option(char *option)
{
	if (option)
		if (!ft_strcmp("-p", option))
			return (1);
	return (0);
}
