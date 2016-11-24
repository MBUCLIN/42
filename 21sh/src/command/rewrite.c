/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 11:59:11 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/24 16:48:56 by mbuclin          ###   ########.fr       */
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

void				display_char(int c, int size, int cursor)
{
	int				col;

	col = tgetnum("co");
	while (size)
	{
		if (cursor >= 0)
		{
			insert_char(c);
			if ((cursor + 1) % col == 0)
				ft_termstr("sf");
		}
		else
			write(1, &c, 1);
		size--;
	}
}

void				rewrite_end(t_command **cmd)
{
	int		pos;
	int		size;
	int		c;
	int		len;

	len = (*cmd)->len;
	pos = (*cmd)->pos;
	ft_termstr("cd");
	save_cursorpos(get_cursor(LOCAT, cmd));
	while ((*cmd)->pos < len)
	{
		c = (*cmd)->command[(*cmd)->pos] == '\t' ?\
				'.' : (*cmd)->command[(*cmd)->pos];
		size = (*cmd)->command[(*cmd)->pos] == '\t' ?\
				get_tabszst(get_cursor(LOCAT, cmd)) : 1;
		(*cmd)->szchar[(*cmd)->pos] = size;
		display_char(c, size, -1);
		(*cmd)->pos++;
	}
	retr_cursorpos(get_cursor(LOCAT, cmd));
	(*cmd)->pos = pos;
	set_command(cmd);
}
