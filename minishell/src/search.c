/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:54:53 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/27 17:37:37 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int		search_cpath(t_shell **shell, char *name, char *cpath)
{
	char	acc[256];
	int		len;

	len = fill_access(&acc, NULL, name);
	if (access(acc, F_OK) == 0)
	{
		if (((*shell)->exec = initiate_exec(cpath, name)) == NULL)
		{
			free(name);
			return (-1);
		}
		return (0);
	}
	return (1);
}

int		search_pathofname(t_shell **sh, char *xname, char **pathes)
{
	int			i;
	char		acc[256];
	int			len;

	i = 0;
	while (pathes[i])
	{
		len = fill_access(&acc, pathes[i], xname);
		if (access(acc, F_OK) == 0)
		{
			if (((*sh)->exec = initiate_exec(pathes[i], xname)) == NULL)
			{
				ft_deltabstr(pathes, ft_tabstrlen(pathes));
				free(xname);
				return (-1);
			}
			ft_deltabstr(pathes, ft_tabstrlen(pathes));
			return (0);
		}
		else
			ft_memset(acc, 0, len);
		i++;
	}
	return (1);
}

int		search_envpath(char *xname, t_shell **sh)
{
	char		*path;
	char		**pathes;

	if ((path = ft_srchenv("PATH=", (*sh)->env)) == NULL)
		return (-1);
	if ((pathes = ft_strsplit(path, ':')) == NULL)
	{
		free(path);
		return (-1);
	}
	return (search_pathofname(sh, xname, pathes));
}
