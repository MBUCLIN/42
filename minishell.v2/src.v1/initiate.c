/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:59:44 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/09 17:43:21 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

t_exec			*initiate_exec(void)
{
	t_exec		*exec;

	if ((exec = (t_exec *)malloc(sizeof(t_exec))) == NULL)
		return (NULL);
	exec->xpath = NULL;
	exec->xname = NULL;
	exec->args = NULL;
	return (exec);
}

t_path			*initiate_path(void)
{
	t_path		*path;

	if ((path = (t_path *)malloc(sizeof(t_path))) == NULL)
		return (NULL);
	path->cpath = NULL;
	path->ppath = NULL;
	if ((path->cpath = getcwd(NULL, 0)) == NULL)
	{
		free(path);
		return (NULL);
	}
	if ((path->ppath = getcwd(NULL, 0)) == NULL)
	{
		free(path->cpath);
		free(path);
		return (NULL);
	}
	return (path);
}

static void		set_shell(t_shell **shell)
{
	(*shell)->prompt = NULL;
	(*shell)->env = NULL;
	(*shell)->path = NULL;
	(*shell)->exec = NULL;
}

t_shell			*initiate_shell(char **env, char *prompt)
{
	t_shell			*shell;

	if ((shell = (t_shell *)malloc(sizeof(t_shell))) == NULL)
		return (NULL);
	set_shell(&shell);
	shell->opt = search_option(prompt);
	if ((shell->prompt = search_prompt(shell->opt, env)) == NULL)
	{
		free(shell);
		return (NULL);
	}
	shell->env = env;
	if ((shell->path = initiate_path()) == NULL)
	{
		free(shell->prompt);
		ft_deltabstr(shell->env, ft_tabstrlen(shell->env));
		free(shell);
		return (NULL);
	}
	return (shell);
}

char		**initiate_env(char **env)
{
	char		**cpy;
	int			check[4];

	if (env == NULL || env[0] == NULL)
	{
		return (recreate_env());
	}
	if ((cpy = ft_tabstrdup(env)) == NULL)
		return (NULL);
	if ((ft_srchenv("PATH=", cpy)) == NULL)
		check[0] = create_pathbinenv(&cpy);
	if ((ft_srchenv("PWD=", cpy)) == NULL)
		check[1] = create_pathenv(&cpy, "PWD=", getcwd(NULL, 0));
	if ((ft_srchenv("OLDPWD", cpy)) == NULL)
		check[2] = create_pathenv(&cpy, "OLDPWD=", getcwd(NULL, 0));
	if ((ft_srchenv("_=", cpy)) == NULL)
		check[3] = create_underscore(&cpy, "_=", getcwd(NULL, 0));
	if (check[0] == -1 || check[1] == -1 || check[2] == -1 || check[3] == -1)
		return (NULL);
	return (cpy);
}
