/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:50:24 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/25 14:05:20 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int		get_cursorpos(t_command **cmd)
{
	int		i;
	int		pos;
	int		cursor;

	pos = (*cmd)->pos;
	i = 0;
	cursor = 0;
	while (i < pos)
	{
		cursor += (*cmd)->szchar[i];
		i++;
	}
	return (cursor + (*cmd)->plen);
}

static int		get_cursorlength(t_command **cmd)
{
	int		i;
	int		len;
	int		cursor;

	len = (*cmd)->len;
	i = 0;
	cursor = 0;
	while (i < len)
	{
		cursor += (*cmd)->szchar[i];
		i++;
	}
	return (cursor + (*cmd)->plen);
}

int				get_cursor(int flagcmd, int flagcs, t_command **cmd)
{
	int			col;
	int			cursor;

	cursor = -1;
	col = tgetnum("co");
	if (flagcmd == LOCAT)
		cursor = get_cursorpos(cmd);
	else if (flagcmd == LENGT)
		cursor = get_cursorlength(cmd);
	if (flagcs && cursor != -1)
	{
		if (flagcs == CSLIN)
			return (cursor / col);
		else
			return (cursor % col);
	}
	return (cursor);
}
