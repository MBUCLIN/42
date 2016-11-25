/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:34:03 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/25 13:39:28 by mbuclin          ###   ########.fr       */
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
	int				line;
	int				minus;

	minus = 0;
	cmd = ft_getcommand();
	ft_putstr((*cmd)->prompt);
	rewrite_end(cmd);
	(*cmd)->pos = save;
	line = get_cursor(LOCAT, CSLIN, cmd);
	if (line == 0)
		minus = 3;
	ft_moovecursor(get_cursor(LOCAT, CSCOL, cmd), line);
	set_command(cmd);
}

static int		erase_command(int old, int cursor, t_command **cmd)
{
	int			newcol;
	int			save;
	int			line;

	newcol = tgetnum("co");
	line = get_cursor(LOCAT, CSLIN, cmd);
	if (old < newcol)
		ft_moovecursor(0, line);
	else
		ft_moovecursor(0, -(line * 2)\
					+ ((cursor % old) + (old - newcol)) / newcol);
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
	rewrite_command(erase_command(oldsz, get_cursor(LOCAT, NONE, cmd), cmd));
}
