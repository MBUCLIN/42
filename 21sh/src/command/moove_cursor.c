/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_cursor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:01:36 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/22 16:14:52 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			get_line(int cursor)
{
	int		col;

	col = tgetnum("co");
	return (cursor / col);
}

int			get_column(int cursor)
{
	int		col;

	col = tgetnum("co");
	return (cursor % col);
}
void		ft_moovecursor(int mv, int up)
{
	ft_termstr("cr");
	while (up)
		if (up < 0)
		{
			ft_termstr("sr");
			up++;
		}
		else
		{
			ft_termstr("do");
			up--;
		}
	while (mv)
	{
		ft_termstr("nd");
		mv--;
	}
}

void		moove_start(int cursor, int co)
{
	int			col;
	int			li;

	ft_termstr("cr");
	col = tgetnum("co");
	li = cursor / col;
	ft_moovecursor(co, (-li));
}

void		moove_end(int cursor, t_command *cmd)
{
	int		col;
	int		co;
	int		li;
	int		lencur;

	col = tgetnum("co");
	lencur = get_cursor(LENGT, &cmd);
	co = lencur % col;
	li = (lencur / col) - (cursor / col);
	ft_moovecursor(co, li);
	cmd->pos = cmd->len;
}
