/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 17:05:41 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/27 17:52:45 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

char		*apply_builtin(t_shell *shell, char *command)
{
	if ((shell->exec->args = get_arguments(command)) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		free(command);
		end_minishell(shell);
	}
	free(command);
	if (!ft_strcmp("exit", shell->exec->xname))
		end_minishell(shell);
	else if (!ft_strcmp("env", shell->exec->xname))
		ft_puttab(shell->env);
	else if (!ft_strcmp("setenv", shell->exec->xname))
		shell->env = add_env(shell);
	else if (!ft_strcmp("unsetenv", shell->exec->xname))
		shell->env = rem_env(shell);
	else
		ft_perror("minishell: command not found: ", shell->exec->xname);
	if (shell->env == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		end_minishell(shell);
	}
	return (NULL);
}

char		*apply_command(t_shell *shell, char *command)
{
	if ((shell->exec->args = get_arguments(command)) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		free(command);
		end_minishell(shell);
	}
	free(command);
	if (!ft_strcmp("cd", shell->exec->xname))
		ft_chdir(shell);
	else
		exec_command(shell);
	return (NULL);
}
