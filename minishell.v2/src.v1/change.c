/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 14:21:03 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/09 17:42:21 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

char		*change_prompt(t_shell *shell)
{
	char		*change;
	if (shell->opt != 1)
		return (shell->prompt);
	free(shell->prompt);
	shell->prompt = NULL;
	if ((change = ft_strdup(shell->path->cpath)) == NULL)
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
