/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 15:48:20 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/09 16:56:40 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

static int		check_isdir(char *arg, char *cpath)
{
	struct stat		buf;
	int				sta;
	char			*path;

	if ((path = ft_creadir(cpath, arg)) == NULL)
		return (2);
	sta = lstat(path, &buf);
	if (sta == -1 || !S_ISDIR(buf.st_mode))
	{
		free(path);
		if (arg[0] == '-' && arg[1] == 0)
			return (0);
		ft_perror("cd: no such file or directory: ", ft_strdup(arg));
		return (-1);
	}
	else if (access(path, X_OK) == -1)
	{
		ft_perror("cd: permission denied: ", path);
		return (-1);
	}
	free(path);
	return (1);
}

t_path			*ft_chdir(char **env, t_path *path, char **args)
{
	int				n;

	if (args[1] == NULL)
		return (goto_pathhome(env, path));
	if (ft_tabstrlen(args) > 2)
	{
		ft_perror("cd: string not in pwd: ", ft_strdup(args[1]));
		return (path);
	}
	else if ((n = check_isdir(args[1], path->cpath)) == -1)
		return (path);
	if (!ft_strcmp("/", args[1]))
		return (goto_slash(path, args[1]));
	if (n == 2)
		return (NULL);
	return (goto_newpath(n, path, args[1]));
}
