/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:34:03 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/24 15:08:11 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void			ft_prompt(int sig)
{
	(void)sig;
	ft_putendl("");
	ft_putstr("$> ");
}

static void		rewrite_command(int save)
{
	t_command		**cmd;
	int				cursor;
	int				minus;

	minus = 0;
	cmd = ft_getcommand();
	ft_putstr((*cmd)->prompt);
	rewrite_end(cmd);
	(*cmd)->pos = save;
	cursor = get_cursor(LOCAT, cmd);
	if (get_line(cursor) == 0)
		minus = 3;
	ft_moovecursor(get_column(cursor), get_line(cursor));
	set_command(cmd);
}

static int		erase_command(int old, int cursor, t_command **cmd)
{
	int			newcol;
	int			save;

	newcol = tgetnum("co");
	if (old < newcol)
		ft_moovecursor(0, get_line(cursor));
	else
		ft_moovecursor(0, -((get_line(cursor) * 2)\
					+ ((cursor % old) + (old - newcol)) / newcol));
	save = (*cmd)->pos;
	(*cmd)->pos = 0;
	set_command(cmd);
	ft_termstr("cd");
	return (save);
}

void			win_resized(int sig)
{
	int				oldsz;
	t_command		**cmd;
	int				new;

	cmd = ft_getcommand();
	oldsz = tgetnum("co");
	if (tgetent(NULL, ft_getenv("TERM=")) != 1)
	{
		signal(sig, SIG_DFL);
		return ;
	}
	if ((*cmd) == NULL || (*cmd)->len == 0)
		return ;
	new = tgetnum("co");
	rewrite_command(erase_command(oldsz, get_cursor(LOCAT, cmd), cmd));
}
