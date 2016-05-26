/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 13:56:37 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/26 19:29:17 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minish.h"

void			ft_perror(char *msg, char *more)
{
	if (more != NULL)
		if ((msg = ft_strjoindfree(msg, more)) == NULL)
		{
			ft_putendl_fd(2, "minishell: malloc error");
			exit(-1);
		}
	ft_putendl_fd(2, msg);
}

static int		main_loop(t_shell *shell)
{
	char		*command;
	int			f;

	if (shell)
		while (1)
		{
			if ((command = read_command(NULL, 0)) == NULL)
			{
				ft_perror("minishell: malloc error", NULL);
				return (1);
			}
			if (ft_strcmp("exit", command) == 0)
				exit(0);
			if ((f = command_not_found(&shell, command)) == 1)
				ft_perror("minishell: command not found: ", command);
			else if (f == 0)
				apply_command(&shell, command);
			else if (f == -1)
			{
				ft_perror("minishell: malloc error", NULL);
				exit(-1);
			}
			free(command);
			command = NULL;
		}
	return (1);
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
	ft_putstr(shell->prompt);
	return (main_loop(shell));
}
