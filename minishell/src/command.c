/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:23:14 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/26 19:43:58 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int		search_envpath(char *xname, t_shell **sh)
{
	char	*path;
	char	**pathes;

	if ((path = ft_srchenv("PATH=", (*sh)->env)) == NULL)
		return (-1)
	if ((pathes = ft_strsplit(path, ':')) == NULL)
	{
		free(path);
		return (-1);
	}
	return (search_pathofname(sh, xname, pathes));
}

int		command_not_found(t_shell **shell, char *command)
{
	char		*name;
	int			f;

	if ((name = get_commandname(command)) == NULL) //DONE
		return (-1);
	if ((f = search_envpath(name, shell)) == 0)
		return (0);
	else if (f == -1)
	{
		free(name);
		return (-1);
	}
	return (search_cpath(name, shell->path->cpath));
}
