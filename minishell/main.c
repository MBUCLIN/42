/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 13:56:37 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/02 18:11:34 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minish.h"

static int		main_loop(t_shell *shell)
{
	char		*command;
	int			f;

	while (1)
	{
		ft_putstr(shell->prompt);
		if ((command = read_command(NULL, 0)) == NULL)
		{
			ft_perror("minishell: malloc error", NULL);
			end_minishell(shell);
		}
		if ((f = find_command(&shell, command)) == -1)
		{
			ft_perror("minishell: malloc error", NULL);
			end_minishell(shell);
		}
		command = apply_command(f, shell, command);
	}
	return (0);
}

int				main(int ac, char **av, char **env)
{
	t_shell		*shell;

	if (ac > 2)
	{
		ft_perror("minishell: wrong number of argument", NULL);
		return (0);
	}
	if ((shell = initiate_shell(env, av[1])) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		return (0);
	}
	return (main_loop(shell));
}
