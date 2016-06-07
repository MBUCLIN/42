/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 15:48:20 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/02 18:54:28 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

t_path		*ft_chdir(char **env, t_path *path, char **args)
{
	int				n;

	if (args[1] == NULL)
		return (goto_pathhome(env, path));
	if (ft_tabstrlen(args) > 2)
	{
		ft_perror("cd: string not in pwd:", args[1]);
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
