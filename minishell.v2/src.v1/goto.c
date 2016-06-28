/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 13:15:19 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/28 15:57:28 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

static int			goto_argpath(t_list *path, char *arg)
{
	char		*npath;

	if (arg[0] != '/')
	{
		if ((npath = ft_strjoin((char *)(path->content), "/")) == NULL)
			return (0);
		if ((npath = ft_strjoinfree(npath, arg)) == NULL)
			return (0);
	}
	else
	{
		if ((npath = ft_strdup(arg)) == NULL)
			return (0);
	}
	if (chdir(npath) == -1)
		return (-1);
	free(npath);
	return (1);
}

static int			goto_lastpath(t_list *path, char *arg)
{
	t_list		*tmp;
	int			index;

	index = ft_atoi(arg + 1);
	if (arg[1] == 0)
		index = 1;
	tmp = ft_lstindex(path, index);
	if (tmp == NULL)
		return (-1);
	if ((chdir((char *)(tmp->content))) == -1)
		return (-1);
	return (1);
}

t_list				*goto_pathhome(char **env, t_list *path)
{
	char	*npath;
	char	*var;
	t_list	*tmp;

	if ((var = ft_srchenv("HOME=", env)) == NULL)
	{
		ft_perror("minishell: cd: HOME is not set", NULL);
		return (path);
	}
	if ((npath = ft_strdup(var)) == NULL)
		end_minishell(-1);
	if ((chdir(npath)) == -1)
	{
		free(npath);
		return (path);
	}
	if ((tmp = ft_lstnew(npath, ft_strlen(npath))) == NULL)
		end_minishell(-1);
	free(npath);
	tmp->next = path;
	path = tmp;
	return (path);
}

t_list				*goto_newpath(int n, t_list *path, char *arg)
{
	t_list		*tmp;
	char		*new;

	if (n == 1)
	{
		if ((n = goto_argpath(path, arg)) == -1)
			return (path);
		if ((new = getcwd(NULL, 0)) == NULL)
			end_minishell(-1);
		if (n == 0)
			end_minishell(-1);
		if ((tmp = ft_lstnew(new, ft_strlen(new))) == NULL)
			end_minishell(-1);
	}
	else
	{
		if ((n = goto_lastpath(path, arg)) == -1)
			return (path);
		if ((new = getcwd(NULL, 0)) == NULL)
			end_minishell(-1);
		if ((tmp = ft_lstnew(new, ft_strlen(new))) == NULL)
			end_minishell(-1);
	}
	free(new);
	tmp->next = path;
	return (tmp);
}

t_list				*goto_slash(t_list *path, char *arg)
{
	t_list		*tmp;

	if ((chdir(arg)) == -1)
		return (path);
	if ((tmp = ft_lstnew(arg, sizeof(char) * 2)) == NULL)
		end_minishell(-1);
	tmp->next = path;
	path = tmp;
	return (path);
}
