/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_cursor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:01:36 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/25 14:05:32 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

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
			ft_termstr("sf");
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
	ft_moovecursor(co, -(li));
}

void		moove_end(t_command *cmd)
{
	int		co;
	int		li;

	li = get_cursor(LENGT, CSLIN, &cmd);
	co = get_cursor(LENGT, CSCOL, &cmd);
	ft_moovecursor(co, li);
	cmd->pos = cmd->len;
	set_command(&cmd);
}
