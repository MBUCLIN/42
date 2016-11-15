/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_cursor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:01:36 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/15 17:00:35 by mbuclin          ###   ########.fr       */
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

void		moove_end(int cursor, t_command *cmd)
{
	int		col;
	int		co;
	int		li;

	col = tgetnum("co");
	co = get_cursor(LENGT, &cmd) % col;
	li = (cursor / col) - (get_cursor(LENGT, &cmd) / col);
	ft_moovecursor(co, li);
	cmd->pos = cmd->len;
}
