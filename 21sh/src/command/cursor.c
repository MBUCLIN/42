/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:50:24 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/31 15:56:16 by mbuclin          ###   ########.fr       */
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
	return (cursor + 3);
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
	return (cursor + 3);
}

int				get_cursor(int flag, t_command **cmd)
{
	if (flag == LOCAT)
		return (get_cursorpos(cmd));
	else if (flag == LENGT)
		return (get_cursorlength(cmd));
	return (-1);
}
