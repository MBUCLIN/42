/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:14:45 by mbuclin           #+#    #+#             */
/*   Updated: 2016/09/26 16:12:37 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

char		**remove_var(char *var, char **env, int len)
{
	char		**new;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if ((new = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		end_minishell(-1);
	new[len] = NULL;
	while (env[i])
	{
		if (ft_strcmp(var, env[i]))
		{
			if ((new[j] = ft_strdup(env[i])) == NULL)
				end_minishell(-1);
			j++;
		}
		free(env[i]);
		i++;
	}
	free(env);
	return (new);
}

void		del_path(t_list *path)
{
	if (path)
	{
		ft_lstdel(&path, ft_delstrcontent);
	}
}

void		del_exec(t_exec *exec)
{
	if (exec)
	{
		if (exec->xpath)
		{
			free(exec->xpath);
			exec->xpath = NULL;
		}
		if (exec->xname)
		{
			free(exec->xname);
			exec->xname = NULL;
		}
		if (exec->args)
			exec->args = ft_deltabstr(exec->args, ft_tabstrlen(exec->args));
		free(exec);
	}
}

void		del_shell(t_shell *shell)
{
	if (shell)
	{
		if (shell->path)
			del_path(shell->path);
		if (shell->exec)
			del_exec(shell->exec);
		if (shell->prompt)
		{
			free(shell->prompt);
			shell->prompt = NULL;
		}
		free(shell);
	}
}
