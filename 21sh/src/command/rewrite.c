/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 11:59:11 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/30 16:13:31 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

t_command			**set_command(t_command **cmd)
{
	static t_command		*saved = NULL;

	if (cmd == NULL)
		return (&saved);
	else
		saved = *cmd;
	return (cmd);
}

t_command			**ft_getcommand(void)
{
	return (set_command(NULL));
}

void				rewrite_end(void)
{
	int		pos;
	t_command		**cmd;
	int		cursor;
	int		len;

	cmd = ft_getcommand();
	len = (*cmd)->len;
	pos = (*cmd)->pos;
	cursor = get_cursor(LOCAT, NONE, cmd);
	save_cursorpos(cursor);
	while ((*cmd)->pos < len)
	{
		display_char(\
				command_settobuf(cmd, (*cmd)->command[(*cmd)->pos], cursor),\
				(*cmd)->szchar[(*cmd)->pos], -1);
		cursor += (*cmd)->szchar[(*cmd)->pos];
		(*cmd)->pos++;
	}
	retr_cursorpos(cursor);
	(*cmd)->pos = pos;
	set_command(cmd);
}
