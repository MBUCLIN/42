/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 17:05:41 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/02 18:57:19 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

static char		*apply_builtin(t_shell *shell)
{
	if (!ft_strcmp("exit", shell->exec->xname))
		end_minishell(shell);
	if (!ft_strcmp("env", shell->exec->xname))
		ft_puttab(shell->env);
	else if (!ft_strcmp("setenv", shell->exec->xname))
		shell->env = add_env(shell->env, shell->exec->args);
	else if (!ft_strcmp("unsetenv", shell->exec->xname))
		shell->env = rem_env(shell->env, shell->exec->args);
	else
		ft_perror("minishell: command not found: ", shell->exec->xname);
	if (shell->env == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		end_minishell(shell);
	}
	del_exec(shell->exec);
	return (NULL);
}

static char		*apply_exec(t_shell *shell)
{
	if (!ft_strcmp("cd", shell->exec->xname))
	{
		if ((shell->path = ft_chdir(shell->env,\
								shell->path, shell->exec->args)) == NULL)
		{
			ft_perror("minishell: malloc error", NULL);
			end_minishell(shell);
		}
		if ((shell->env = ft_chgvalue("PWD=", shell->path->cpath,\
									shell->env)) == NULL)
		{
			ft_perror("minishell: malloc error", NULL);
			end_minishell(shell);
		}
	}
	else
		exec_command(shell);
	del_exec(shell->exec);
	if ((shell->prompt = change_prompt(shell)) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		end_minishell(shell);
	}
	return (NULL);
}

char			*apply_command(int f, t_shell *shell, char *command)
{
	if (!ft_strcmp(command, "") || f == -2)
	{
		if (command)
			free(command);
		return (NULL);
	}
	else if ((shell->exec->args = get_arguments(command)) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		free(command);
		end_minishell(shell);
	}
	free(command);
	if (f == 0 && ft_strcmp("env", command))
		return (apply_exec(shell));
	return (apply_builtin(shell));
}
