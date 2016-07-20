/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 17:05:41 by mbuclin           #+#    #+#             */
/*   Updated: 2016/07/18 15:43:53 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

static void			apply_cd(t_shell **sh, t_exec *exec, char **env)
{
	if (((*sh)->path = ft_chdir(env, (*sh)->path, exec->args)) == NULL)
		end_minishell(-1);
	if ((env = ft_chgvalue("PWD=", (*sh)->path->content, env)) == NULL)
		end_minishell(-1);
	if ((*sh)->path->next && (env = ft_chgvalue("OLDPWD=",\
							(*sh)->path->next->content, env)) == NULL)
		end_minishell(-1);
	change_path(&((*sh)->path), 0);
	if (((*sh)->prompt = change_prompt((*sh))) == NULL)
		end_minishell(-1);
}

static void			ft_echo(char **args)
{
	int		i;
	char	*print;

	i = 1;
	while (args[i])
	{
		if ((print = ft_treatquote(args[i])) == NULL)
			end_minishell(-1);
		if (i != 1)
			ft_printf(" %s", print);
		else
			ft_putstr(print);
		free(print);
		print = NULL;
		i++;
	}
	ft_putchar('\n');
}

static void			apply_builtin(t_exec *exec, t_shell **shell)
{
	if (!ft_strcmp(exec->xname, "exit"))
		ft_exit(exec->args);
	else if (!ft_strcmp(exec->xname, "echo"))
		ft_echo(exec->args);
	else if (!ft_strcmp(exec->xname, "cd"))
		apply_cd(shell, exec, (*shell)->env);
	else if (!ft_strcmp(exec->xname, "env"))
		(*shell)->env = env_builtin((*shell), exec->args);
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
