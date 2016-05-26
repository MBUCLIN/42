/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:54:53 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/26 19:55:48 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int		search_pathofname(t_shell **sh, char *xname, char **pathes)
{
	int			i;
	char		access[256];
	int			len;

	i = 0;
	while (pathes[i])
	{
		if (check_access(pathes[i], 0) == 0)
		{
			len = fill_access(&access, pathes[i], xname);
			if (check_access(access, 3) == 0)
			{
				if (((*sh)->exec = initiate_exec(access)) == NULL)
					return (-1);
				return (0);
			}
			else
				ft_memset(access, 0, len);
		}
		i++;
	}
	return (1);
}

int		search_envpath(char *xname, t_shell **sh)
{
	char		*path;
	char		**pathes;

	if ((path = ft_srchenv("PATH=", (*ev)->env)) == NULL)
		return (-1);
	if ((pathes = ft_strsplit(path, ':')) == NULL)
	{
		free(path);
		return (-1);
	}
	return (search_pathofname(sh, xname, pathes));
}

access(path, X_OK | X_R);
