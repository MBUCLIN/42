/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:41:51 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/30 15:49:26 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int				command_settobuf(t_command **cmd, int c, int cursor)
{
	int		col;

	col = tgetnum("co");
	if (c == '\t')
	{
		(*cmd)->command[(*cmd)->pos] = c;
		(*cmd)->szchar[(*cmd)->pos] = get_tabszst(cursor);
		return (' ');
	}
	else if (c == '\n')
	{
		(*cmd)->command[(*cmd)->pos] = c;
		(*cmd)->szchar[(*cmd)->pos] = col - (cursor % col);
	}
	else
	{
		c = c <= 31 ? '[' : c;
		c = c >= 127 ? '~' : c;
		(*cmd)->command[(*cmd)->pos] = c;
		(*cmd)->szchar[(*cmd)->pos] = 1;
	}
	return (c);
}

static int		command_end(char *buf, t_command **cmd)
{
	int		cursor;

	cursor = get_cursor(LOCAT, NONE, cmd);
	command_settobuf(cmd, *buf, cursor);
	return (1);
}

static int		insert_buf_to_command(t_command **cmd, char *buf, int cursor)
{
	unsigned int		i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		buf[i] = command_settobuf(cmd, buf[i], cursor);
		cursor += (*cmd)->szchar[(*cmd)->pos];
		(*cmd)->pos++;
		(*cmd)->len++;
		i++;
	}
	if (i < ft_strlen(buf))
		return (i);
	return (0);
}

static void		push_sub_to_command(t_command **cmd, char *sub, int cursor)
{
	int		i;

	i = 0;
	while (sub[i])
	{
		command_settobuf(cmd, sub[i], cursor);
		cursor += (*cmd)->szchar[(*cmd)->pos];
		(*cmd)->pos++;
		i++;
	}
	free(sub);
}

int				command_insert(char *buf)
{
	t_command		**cmd;
	int				ret;
	int				pos;
	char			*sub;

	cmd = ft_getcommand();
	pos = (*cmd)->pos;
	if ((sub = ft_strsub((*cmd)->command,\
						pos, ft_strlen((*cmd)->command + pos))) == NULL)
		ft_exitshell("21sh", ERRMALLOC, NULL);
	(*cmd)->command[(*cmd)->pos] = 0;
	ret = insert_buf_to_command(cmd, buf, get_cursor(LOCAT, NONE, cmd));
	(*cmd)->command[(*cmd)->pos] = 0;
	push_sub_to_command(cmd, sub, get_cursor(LOCAT, NONE, cmd));
	if (buf[ret] == '\n')
		ret += command_end(buf + ret, cmd);
	(*cmd)->pos = pos;
	set_command(cmd);
	return (ret);
}
