/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 16:06:51 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/28 17:43:43 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int			check_isdir(char *arg)
{
	struct stat		buf;
	int				sta;

	sta = lstat(arg, &buf)
	if (!S_ISDIR(buf.mode) || sta == -1)
	{
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
	if ((S_ISREP(buf.mode) && access(path, X_OK) == 0) && !sta)
		return (sta);
	return (-1);
}

static int	check_format(char *arg)
{
	if (ft_strchr(arg, '=') == NULL)
		return (-1);
}

int			check_argenv(char *arg)
{
	int			i;

	i = 1;
	while (arg[i])
	{
		if (check_format(arg[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
