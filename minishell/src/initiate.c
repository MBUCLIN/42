/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:59:44 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/07 13:05:17 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

t_exec			*initiate_exec(char *path, char *xname)
{
	t_exec		*exec;

	if ((exec = (t_exec *)malloc(sizeof(t_exec))) == NULL)
		return (NULL);
	exec->xpath = NULL;
	exec->xname = NULL;
	exec->args = NULL;
	if (path)
		if ((exec->xpath = ft_strdup(path)) == NULL)
		{
			free(exec);
			return (NULL);
		}
	exec->xname = xname;
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
	path->ppath = NULL;
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
	if ((shell->prompt = search_prompt(prompt, env)) == NULL)
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
