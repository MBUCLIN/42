/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 16:06:51 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/08 16:46:13 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int			check_builtin(char *name)
{
	if (!ft_strcmp("env", name) || !ft_strcmp("cd", name) ||\
		!ft_strcmp("setenv", name) || !ft_strcmp("unsetenv", name) ||\
		!ft_strcmp("exit", name))
		return (0);
	return (-1);
}

int			check_isdir(char *arg, char *cpath)
{
	struct stat		buf;
	int				sta;
	char			*path;

	if ((path = ft_creadir(cpath, arg)) == NULL)
		return (2);
	sta = lstat(path, &buf);
	free(path);
	if (sta == -1 || !S_ISDIR(buf.st_mode))
	{
		if (arg[0] == '-' && arg[1] == 0)
			return (0);
		ft_perror("cd: no such file or directory: ", arg);
		return (-1);
	}
	else if (access(path, X_OK) == -1)
	{
		ft_perror("cd: permission denied: ", arg);
		return (-1);
	}
	return (1);
}

int			check_exec(char *path)
{
	struct stat		buf;
	int				sta;

	sta = lstat(path, &buf);
	if (!sta && (S_ISREG(buf.st_mode) && access(path, X_OK) == 0))
		return (sta);
	return (-1);
}
