/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:41:51 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/25 17:17:26 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int		command_settobuf(t_command **cmd, int c, int cursor)
{
	int		col;

	col = tgetnum("co");
	if (c == '\t')
	{
		(*cmd)->command[(*cmd)->pos] = c;
		(*cmd)->szchar[(*cmd)->pos] = get_tabszst(cursor);
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

static void		command_end(char *buf, t_command **cmd)
{
	int		li;
	int		i;
	int		cursor;

	i = 0;
	while ((*cmd)->command[(*cmd)->pos])
		(*cmd)->pos++;
	cursor = get_cursor(LOCAT, NONE, cmd);
	ft_moovecursor(get_cursor(LOCAT, CSCOL, cmd),\
					get_cursor(LOCAT, CSLIN, cmd));
	buf[i] = command_settobuf(cmd, buf[i], cursor);
	return (1);
}

static int		command_buffer_insert(char *buf, t_command **cmd,\
										int cursor, int len)
{
	int		i;
	int		n;
	int		ret;

	i = 0;
	n = 0;
	ret = 0;
	while (buf[i] && buf[i] != '\n')
	{
		buf[i] = command_settobuf(cmd, buf[i], cursor);
		(*cmd)->pos++;
		cursor++;
		i++;
	}
	if (i < ft_strlen(buf))
		ret = command_end(buf + i, cmd, len);
	set_command(cmd);
	return (ret);
}

static int		command_pushchar(t_command **cmd, int len)
{
	char		*sub_moove;
	int			j;
	int			save;

	j = 0;
	save = (*cmd)->pos;
	if ((sub = ft_strsub((*cmd)->command, (*cmd)->pos,\
					ft_strlen((*cmd)->command + (*cmd)->pos))) == NULL)
		ft_exitshell("21sh", ERRMALLOC, NULL);
	(*cmd)->pos += len;
	(*cmd)->len += len;
	while (sub[j])
	{
		(*cmd)->command[(*cmd)->pos] = sub[j];
		(*cmd)->szchar[(*cmd)->pos] = sub[j] == '\t' ?\
						get_tabszst(get_cursor(LOCAT, NONE, cmd)) : 1;
		j++;
		(*cmd)->pos++;
	}
	(*cmd)->pos = save;
	free(sub);
	return (ft_strlen(*cmd)->command + (*cmd)->pos);
}

int				command_insert(char *buf)
{
	t_command		**cmd;
	int				ret;
	int				pos;

	cmd = ft_getcommand();
	pos = (*cmd)->pos;
	command_pushchar(cmd, ft_linelen(buf));
	ret = command_buffer_insert(buf, cmd, get_cursor(LOCAT, NONE, cmd));
	(*cmd)->pos = pos;
	set_command(cmd);
	return (ret);
}
