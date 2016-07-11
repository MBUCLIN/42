/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:21:03 by mbuclin           #+#    #+#             */
/*   Updated: 2016/07/08 16:43:04 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void		change_path(t_list **node, int i)
{
	if ((*node)->next)
		change_path(&(*node)->next, ++i);
	if (i > 9)
		ft_lstdelone(node, ft_delstrcontent);
}

char		*change_prompt(t_shell *shell)
{
	char		*change;

	if (shell->opt != 1)
		return (shell->prompt);
	free(shell->prompt);
	shell->prompt = NULL;
	if ((change = ft_strdup((char *)(shell->path->content))) == NULL)
		end_minishell(-1);
	if ((change = ft_strjoinfree(change, " ")) == NULL)
		end_minishell(-1);
	return (change);
}

char		**change_args(char **args, char **env)
{
	int		i;
	char	*change;
	char	*srch;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '$')
		{
			if ((srch = ft_strjoin(((args[i]) + 1), "=")) == NULL)
				end_minishell(-1);
			if ((change = ft_srchenv(srch, env)))
			{
				free(args[i]);
				if ((args[i] = ft_strdup(change)) == NULL)
					end_minishell(-1);
			}
		}
		i++;
	}
	return (args);
}

char		**change_underscore(t_exec *exec, char **env)
{
	int			i;
	int			len;
	char		*last;

	i = 0;
	if (!ft_strcmp(exec->xname, "echo") && ft_srchenv("$_", exec->args))
		return (env);
	len = ft_tabstrlen(exec->args) - 1;
	if (!ft_strcmp(exec->xname, "env") || !ft_strcmp(exec->xname, "setenv"))
		last = exec->args[0];
	else
		last = exec->args[len];
	while (env[i])
	{
		if (ft_strstr(env[i], "_="))
		{
			free(env[i]);
			env[i] = NULL;
			if ((env[i] = ft_strjoin("_=", last)) == NULL)
				end_minishell(-1);
			return (env);
		}
		i++;
	}
	return (env);
}

int			env_to_change(char **env, char *arg)
{
	char	*name;
	int		i;

	i = 0;
	if ((name = cut_envvar(arg)) == NULL)
		return (0);
	if ((name = ft_strjoinfree(name, "=")) == NULL)
		end_minishell(-1);
	while (env[i])
	{
		if (ft_strstr(env[i], name))
		{
			free(name);
			return (1);
		}
		i++;
	}
	free(name);
	return (0);
}
