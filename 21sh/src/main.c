/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 13:23:24 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/21 15:03:02 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static void			main_loop(void)
{
	t_command	*cmd;
	char		*name;
	char		*command;

	while (42)
	{
		cmd = NULL;
		command = NULL;
		if ((name = ft_getenv("TERM=")) == NULL)
			command = init_noncanon_read();
		else if (!canonize_input(name))
			command = init_noncanon_read();
		else if ((cmd = read_loop("$> ", 0, NULL)) == NULL)
		{
			sherror("21sh", ERRMALLOC, NULL);
			noncanonize_input(name);
			return ;
		}
		else
			noncanonize_input(name);;
		if (command)
		{
			ft_printf("|%s| : command\n", command);
			free(command);
		}
		else
		{
			ft_printf("|%s| : cmd->command\n", cmd->command);
			del_command(cmd);
		}
	}
}

int					main(void)
{
	t_list			*env;
	t_list			*tmp;

	env = NULL;
	create_env();
	env = get_env(NULL);
	tmp = env;
	main_loop();
	return (0);
}
