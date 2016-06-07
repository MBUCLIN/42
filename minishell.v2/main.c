/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 13:56:37 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/07 16:04:11 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minish.h"

static int		main_loop(t_shell *shell)
{
	char		*command;

	while (1)
	{
		ft_putstr(shell->prompt);
		if ((command = read_command(NULL, 0)) == NULL)
		{
			ft_perror("minishell: malloc error", NULL);
			end_minishell(-1);
		}
		shell->exec = find_commandtype(shell, command);
//		command = apply_command(f, shell, command);
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
	{
		ft_perror("minishell: malloc error", NULL);
		return (-1);
	}
	if ((shell = initiate_shell(env, av[1])) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		return (-1);
	}
	ft_putstr(shell->prompt);
	return (main_loop(shell));
}
