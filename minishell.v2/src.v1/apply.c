/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 17:05:41 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/08 16:44:27 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

static void			apply_cd(t_shell **sh, t_exec *exec, char **env)
{
	if ((path = ft_chdir(env, (*sh)->path, exec->args)) == NULL)
		end_minishell(-1);
	if ((env = ft_chgvalue("PWD", (*sh)->path->cpath, env)) == NULL ||\
		(env = ft_chgvalue("OLDPWD", (*sh)->path->ppath, env)) == NULL)
		end_minishell(-1);
	if (((*sh)->prompt = change_prompt((*sh))) == NULL)
		end_minishell(-1);
}

static void			apply_builtin(t_exec *exec, t_shell **shell)
{
	if (!ft_strcmp(exec->xname, "exit"))
		end_minishell(ft_atoi(exec->args[1]));
	else if (!ft_strcmp(exec->xname, "cd"))
		apply_cd(shell, exec, (*shell)->env);
	else if (!ft_strcmp(exec->xname, "env"))
		ft_puttab((*shell)->env);
	else if (!ft_strcmp(exec->xname, "setenv"))
		(*shell)->env = add_env((*shell)->env, exec->args);
	else if (!ft_strcmp(exec->xname, "unsetenv"))
		(*shell)->env = rem_env((*shell)->env, exec->args);
	if ((*shell)->env == NULL)
		end_minishell(-1);
}

void				apply_command(t_exec *exec, t_shell **shell)
{
	if (exec->xpath == NULL)
		apply_builtin(exec, shell);
	else
		exec_command(*shell);
	del_exec(exec);
	(*shell)->exec = NULL;
}
