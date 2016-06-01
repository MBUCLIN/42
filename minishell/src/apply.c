/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 17:05:41 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/01 16:39:08 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

char		*apply_builtin(t_shell *shell, char *command)
{
	if (!ft_strcmp("exit", command))
		end_minishell(shell);
	if ((shell->exec->args = get_arguments(command)) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		free(command);
		end_minishell(shell);
	}
	free(command);
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

char		*apply_command(t_shell *shell, char *command)
{
	ft_putendl("get arg");
	if ((shell->exec->args = get_arguments(command)) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		free(command);
		end_minishell(shell);
	}
	check_args(shell->exec->args);
	if (!ft_strcmp("", command))
	{
		free(command);
		return (NULL);
	}
	free(command);
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
