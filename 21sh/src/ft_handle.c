/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:34:03 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/06 14:35:22 by mbuclin          ###   ########.fr       */
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

	(void)sig;
	cmd = ft_getcommand();
	oldsz = tgetnum("co");
	if (tgetent(NULL, ft_getenv("TERM=")) != 1)
	{
		ft_putendl("tgetent KO");
		signal(sig, SIG_DFL);
		return ;
	}
	place_cursor(oldsz, get_cursor(LOCAT, cmd), *cmd);
}
