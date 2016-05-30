/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 16:06:51 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/30 13:49:20 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int			check_isdir(char *arg)
{
	struct stat		buf;
	int				sta;

	sta = lstat(arg, &buf);
	if (!S_ISDIR(buf.st_mode) || sta == -1)
	{
		if (arg[0] == '-' && arg[1] == 0)
			return (1);
		ft_perror("cd: no such file or directory: ", arg);
		return (-1);
	}
	return (0);
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

static int	check_format(char *arg)
{
	if (ft_strchr(arg, '=') == NULL)
		return (-1);
	return (0);
}

int			check_argenv(char *arg)
{
	if (check_format(arg) == -1)
		return (-1);
	return (0);
}
