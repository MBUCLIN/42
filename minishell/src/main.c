/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 13:56:37 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/03 15:10:34 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

static int		main_loop(t_shell *shell)
{
	char		*command;

	while (1)
	{
		signal(SIGINT, ft_handle);
		ft_putstr(shell->prompt);
		if ((command = read_command(NULL, 0)) == NULL)
			end_minishell(-1);
		shell->exec = find_commandtype(shell, command);
		free(command);
		command = NULL;
		if (shell->exec->xname == NULL)
		{
			del_exec(shell->exec);
			shell->exec = NULL;
			continue ;
		}
		if (!ft_strcmp(shell->exec->xname, ""))
			continue ;
		shell->exec->args = change_args(shell->exec->args, shell->env);
		shell->env = change_underscore(shell->exec, shell->env);
		apply_command(shell->exec, &shell);
	}
	return (0);
}

int				main(int ac, char **av, char **env)
{
	t_shell		*shell;
	char		**cpyenv;

	if (ac > 2)
	{
		ft_perror("minishell: wrong number of argument", NULL);
		return (0);
	}
	if ((cpyenv = initiate_env(env)) == NULL)
		end_minishell(-1);
	if ((shell = initiate_shell(cpyenv, av[1])) == NULL)
		end_minishell(-1);
	return (main_loop(shell));
}
