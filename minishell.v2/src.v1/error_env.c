/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 15:55:13 by mbuclin           #+#    #+#             */
/*   Updated: 2016/07/14 17:43:47 by mbuclin          ###   ########.fr       */
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

int			error_init(char **arg)
{
	int		i;

	i = 2;
	while (arg[i])
	{
		if (ft_strchr(arg[i], '=') == NULL && arg[i + 1] != NULL)
		{
			ft_putstr_fd("env: -i: ", 2);
			ft_putstr_fd(arg[i], 2);
			ft_putendl_fd(2, ": Invalid argument");
			return (1);
		}
		i++;
	}
	return (0);
}
