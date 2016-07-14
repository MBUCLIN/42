/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 15:48:20 by mbuclin           #+#    #+#             */
/*   Updated: 2016/07/12 14:26:20 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int				check_isdir(char *arg, char *cpath, char *exec)
{
	struct stat		buf;
	int				sta;
	char			*path;

	if ((path = ft_creadir(cpath, arg)) == NULL)
		return (2);
	sta = lstat(path, &buf);
	if (sta == -1 || (!S_ISDIR(buf.st_mode) && !S_ISLNK(buf.st_mode)))
	{
		free(path);
		if (arg[0] == '-' && (arg[1] == 0 || ft_isstrdigit(arg + 1)))
			return (0);
		ft_putstr_fd(exec, 2);
		ft_perror(": no such file or directory: ", ft_strdup(arg));
		return (-1);
	}
	else if (access(path, X_OK) == -1)
	{
		ft_putstr_fd(exec, 2);
		ft_perror(": permission denied: ", path);
		return (-1);
	}
	free(path);
	return (1);
}

t_list			*ft_chdir(char **env, t_list *path, char **args)
{
	int				n;

	if (args[1] == NULL || ft_isempty(args[1]))
		return (goto_pathhome(env, path));
	if (ft_tabstrlen(args) > 2)
	{
		ft_perror("cd: string not in pwd: ", ft_strdup(args[1]));
		return (path);
	}
	else if ((n = check_isdir(args[1], (char *)(path->content), args[0])) == -1)
		return (path);
	if (args[1][0] == '/' && ft_strlen(args[1]) == 1)
		return (goto_slash(path, args[1]));
	if (n == 2)
		return (NULL);
	return (goto_newpath(n, path, args[1]));
}
