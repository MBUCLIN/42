/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:34:03 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/09 13:38:49 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void		ft_prompt(int sig)
{
	(void)sig;
	ft_putendl("");
	ft_putstr("$> ");
}

void		win_resized(int sig)
{
	int				oldsz;
	t_command		**cmd;
	int				new;
	int				tmp;

	cmd = ft_getcommand();
	oldsz = tgetnum("co");
	if (tgetent(NULL, ft_getenv("TERM=")) != 1)
	{
		ft_putendl("tgetent KO");
		signal(sig, SIG_DFL);
		return ;
	}
	if ((*cmd) == NULL || (*cmd)->len == 0)
		return ;
	new = tgetnum("co");
	while (42)
	{
		if ((tmp = tgetnum("co")) == new)
			break ;
		new = tmp;
	}
	place_cursor(oldsz, get_cursor(LOCAT, cmd), *cmd);
}
