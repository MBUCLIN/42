/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 17:05:41 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/06 16:25:23 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

static char		*apply_builtin(t_shell *shell)
{
	if (!ft_strcmp("exit", shell->exec->xname))
		end_minishell(NULL);
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
	shell->exec = NULL;
	return (NULL);
}

static void		apply_cd(t_shell *sh, t_exec *exec, t_path *path, char **env)
{
	if ((path = ft_chdir(env, path, exec->args)) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		end_minishell(sh);
	}
	if ((env = ft_chgvalue("PWD", path->cpath, env)) == NULL ||\
		(env = ft_chgvalue("OLDPWD", path->ppath, env)) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		end_minishell(sh);
	}
}

static char		*apply_exec(t_shell *shell)
{
	if (!ft_strcmp("cd", shell->exec->xname))
		apply_cd(shell, shell->exec, shell->path, shell->env);
	else
		exec_command(shell);
	del_exec(shell->exec);
	shell->exec = NULL;
	if ((shell->prompt = change_prompt(shell)) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		end_minishell(shell);
	}
	return (NULL);
}

char			*apply_command(int f, t_shell *shell, char *command)
{
	if (f == -2 || !ft_strcmp(command, ""))
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
	if ((shell->exec->args = change_arg(shell->exec->args,\
											shell->env)) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		end_minishell(shell);
	}
	if (f == 0 && ft_strcmp("env", command))
		return (apply_exec(shell));
	return (apply_builtin(shell));
}
