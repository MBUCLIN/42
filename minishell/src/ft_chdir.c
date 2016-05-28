/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 15:48:20 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/28 17:39:23 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

t_path		*ft_chdir(t_path *path, char **args)
{
	char			*npath;

	if (ft_tabstrlen(args) > 2)
	{
		ft_perror("cd: string not in pwd: ", args[1]);
		return (path);
	}
	if (check_isdir(args[1]) == -1)
		return (path);
	if ((npath = get_fullpath(path, args[1])) == NULL)
	{
		del_path(path);
		return (NULL);
	}
	if (chdir(npath) == -1)
	{
		ft_perror("cd: builtin has failed: ", args[1]);
		return (path);
	}
	free(path->ppath);
	path->ppath = path->cpath;
	path->cpath = npath;
	return (path);
}
