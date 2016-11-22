/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 13:23:24 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/22 15:07:06 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static char			*read_command(int canon)
{
	t_command		*cmd;
	char			*command;

	if (canon == 0)
		if ((cmd = read_loop("$> ", 0, NULL)) == NULL)
			ft_exitshell("21sh", ERRMALLOC, NULL);
	if (canon == 1)
		if ((command = init_noncanon_read()) == NULL)
			ft_exitshell("21sh", ERRMALLOC, NULL);
	if (canon == 1)
		return (command);
	else if (canon == 0)
		if ((command = ft_strdup(cmd->command)) == NULL)
			ft_exitshell("21sh", ERRMALLOC, NULL);
	del_command(cmd);
	return (command);
}

static void			main_loop(void)
{
	char		*name;
	char		*command;
	int			canon;

	while (42)
	{
		command = NULL;
		canon = 0;
		if ((name = ft_getenv("TERM=")) == NULL)
			canon = 1;
		if (canon == 0)
			if (canonize_input(name) == 0)
				canon = 1;
		command = read_command(canon);
		save_history(command);
		noncanonize_input(name);
		ft_printf("|%s| : command\n", command);
		free(command);
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
