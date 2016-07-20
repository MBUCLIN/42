/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 15:55:13 by mbuclin           #+#    #+#             */
/*   Updated: 2016/07/18 16:36:42 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int			error_unset(char **arg)
{
	int			i;

	i = 1;
	while (arg[i])
	{
		if (ft_strchr(arg[i], '=') || ft_strchr(arg[i], '$'))
		{
			ft_putstr_fd("env: unsetenv ", 2);
			ft_putstr_fd(arg[i], 2);
			ft_putendl_fd(2, ": Invalid argument");
			return (1);
		}
		i++;
	}
	if (i == 1)
	{
		ft_putendl_fd(2, "env: option requires an argument -- u");
		ft_putendl_fd(2, "usage: [env -u || unsetenv] NAME [...]");
		return (1);
	}
	return (0);
}

int			error_set(char **arg)
{
	int			i;

	i = 1;
	while (arg[i])
	{
		if (!ft_strchr(arg[i], '=') || ft_strchr(arg[i], '$'))
		{
			ft_putstr_fd("env: setenv ", 2);
			ft_putstr_fd(arg[i], 2);
			ft_putendl_fd(2, ": Invalid argument");
			return (1);
		}
		i++;
	}
	if (i == 1)
	{
		ft_putendl_fd(2, "setenv: requires an argument");
		ft_putendl_fd(2, "usage: [env || setenv] NAME=value [...]");
		return (1);
	}
	return (0);
}

static int	file_check(char *file)
{
	struct stat		buf;

	if (file[0] != '/' && file[1] != '/' && file[2] != '/')
	{
		ft_perror("env: no such file or directory -- ", ft_strdup(file));
		return (0);
	}
	if (stat(file, &buf) == -1)
	{
		ft_perror("env: no such file or directory -- ", ft_strdup(file));
		return (0);
	}
	if (!S_ISREG(buf.st_mode))
	{
		ft_perror("env: no such file or directory -- ", ft_strdup(file));
		return (0);
	}
	if (!(S_IXUSR & buf.st_mode))
	{
		ft_perror("env: permission dinied: ", ft_strdup(file));
		return (0);
	}
	return (1);
}

int			error_init(char **arg)
{
	int		i;

	i = 2;
	while (arg[i])
	{
		if (arg[i + 1] == NULL && !ft_strcmp(arg[i], "env"))
			return (1);
		if (arg[i + 1] == NULL && !file_check(arg[i]))
			return (1);
		if (ft_strchr(arg[i], '=') == NULL && arg[i + 1] != NULL)
		{
			ft_putstr_fd("env: -i: ", 2);
			ft_putstr_fd(arg[i], 2);
			ft_putendl_fd(2, ": Invalid argument");
			return (1);
		}
		i++;
	}
	if (i == 2)
		return (1);
	return (0);
}
