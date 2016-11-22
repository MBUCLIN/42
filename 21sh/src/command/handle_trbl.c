/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_trbl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 16:18:38 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/22 14:55:58 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int		get_newcur(int add, t_command **cmd, int cursor, int col)
{
	int		newcur;
	int		lengt;

	lengt = get_cursor(LENGT, cmd);
	newcur = cursor + (add * col);
	if (newcur < (*cmd)->plen)
		newcur = (*cmd)->plen;
	else if (lengt < newcur)
		newcur = lengt;
	while (((add == -1 && cursor > newcur) ||\
			(add == 1 && cursor < newcur)))
	{
		if (add == -1)
			(*cmd)->pos += add;
		cursor += (add * (*cmd)->szchar[(*cmd)->pos]);
		if (add == 1)
			(*cmd)->pos += add;
	}
	return (cursor);
}

static void		handle_updown(int add, t_command **cmd)
{
	int			cursor;
	int			col;
	int			newcur;
	int			mv;

	cursor = get_cursor(LOCAT, cmd);
	col = tgetnum("co");
	if ((add == -1 && cursor / col == 0) ||\
		(add == 1 && cursor / col == get_cursor(LENGT, cmd) / col))
		return ;
	newcur = get_newcur(add, cmd, cursor, col);
	mv = newcur % col;
	if (add == -1)
	{
		ft_termstr("up");
		ft_termstr("cr");
	}
	else
		ft_termstr("do");
	while (mv > 0)
	{
		ft_termstr("nd");
		mv--;
	}
	set_command(cmd);
}

static void		handle_rightleft(int add, t_command **cmd)
{
	int		n;
	int		szchar;

	if ((add == 0 && (*cmd)->pos == (*cmd)->len) ||\
		(add == -1 && (*cmd)->pos == 0))
		return ;
	n = -1;
	while (++n != (szchar = (*cmd)->szchar[(*cmd)->pos + add]))
		if (add == -1)
		{
			if (left_moove(get_cursor(LOCAT, cmd), szchar, *cmd) == 1)
				break ;
		}
		else
			right_moove(*cmd, n);
	if (add == -1)
		(*cmd)->pos--;
	else
		(*cmd)->pos++;
	set_command(cmd);
}

void			handle_trbl(char *buf, t_command **cmd)
{
	int		len;

	len = ft_strlen(buf);
	if (len == 3)
	{
		if (buf[len - 1] == 68)
		{
			handle_rightleft(-1, cmd);
		}
		else
		{
			handle_rightleft(0, cmd);
		}
	}
	else
	{
		if (buf[len - 1] == 65)
			handle_updown(-1, cmd);
		else
			handle_updown(1, cmd);
	}
}
