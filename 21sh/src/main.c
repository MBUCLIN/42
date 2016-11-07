/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 13:23:24 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/04 14:12:00 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static void			main_loop(void)
{
	char		*command;
	char		*name;

	while (42)
	{
		if ((name = ft_getenv("TERM=")) == NULL)
			return ;
//			command = readnon_canon();
		else if (!canonize_input(name))
			return ;
//			command = readnon_canon();
		else if ((command = read_loop()) == NULL)
		{
			sherror("21sh", ERRMALLOC, NULL);
			noncanonize_input(name);
			return ;
		}
		else
			noncanonize_input(name);
		ft_termstr("cl");
		ft_printf("\n|%s| : command\n", command);
		free(command);
		command = NULL;
	}
}

int					main(void)
{
	extern char		**environ;
	t_list			*env;
	t_list			*tmp;

	if ((env = ft_artol(environ)) == NULL)
		sherror("21sh", ERRMALLOC, NULL);
	else
	{
		tmp = env;
		while (tmp)
		{
			ft_putendl(tmp->content);
			tmp = tmp->next;
		}
		get_env(env);
		main_loop();
		ft_lstdel(&env, ft_delstrcontent);
	}
	return (0);
}
