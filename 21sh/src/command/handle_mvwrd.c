/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mvwrd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:37:25 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/22 15:09:52 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void		moove_cursor(int way, t_command **cmd)
{
	int		cursor;

	cursor = get_cursor(LOCAT, cmd);
	if (way == -1)
		left_moove(cursor, 0, *cmd);
	else
		right_moove(*cmd, 0);
}

static void		moove_wlft(t_command **cmd)
{
	while ((*cmd)->pos > 0 && !ft_isblank((*cmd)->command[(*cmd)->pos - 1]))
	{
		moove_cursor(-1, cmd);
		(*cmd)->pos--;
	}
}

static void		moove_wrgt(t_command **cmd)
{
	while ((*cmd)->pos < (*cmd)->len &&\
			!ft_isblank((*cmd)->command[(*cmd)->pos + 1]))
	{
		moove_cursor(1, cmd);
		(*cmd)->pos++;
	}
}

void			handle_mvwrd(char *buf, t_command **cmd)
{
	if (buf[3] == 68)
		moove_wlft(cmd);
	else
		moove_wrgt(cmd);
}
