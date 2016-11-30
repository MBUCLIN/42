/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:45:54 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/30 16:20:03 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void			insert_char(int c)
{
	char		*req;

	if ((req = tgetstr("im", NULL)) == NULL)
	{
		if ((req = tgetstr("ic", NULL)) == NULL)
			write(1, &c, 1);
		else
		{
			tputs(req, 1, ft_writechar);
			write(1, &c, 1);
		}
	}
	else
	{
		tputs(req, 1, ft_writechar);
		if ((req = tgetstr("ic", NULL)) == NULL)
			write(1, &c, 1);
		else
		{
			tputs(req, 1, ft_writechar);
			write(1, &c, 1);
		}
		ft_termstr("ei");
	}
}

void			display_char(int c, int size, int cursor)
{
	int			col;
	int			i;

	c = c == '\t' ? ' ' : c;
	i = 0;
	col = tgetnum("co");
	while (i < size)
	{
		if (cursor >= 0)
			insert_char(c);
		else
			write(1, &c, 1);
		i++;
		if (cursor >= 0 &&\
			(cursor + i) % col == 0)
			ft_moovecursor(0, 1);
	}
}

static void		buf_in_stream(int len)
{
	int			i;
	t_command	**cmd;
	int			cursor;

	cmd = ft_getcommand();
	i = 0;
	cursor = get_cursor(LOCAT, NONE, cmd);
	while (i < len)
	{
		display_char((*cmd)->command[(*cmd)->pos],\
					(*cmd)->szchar[(*cmd)->pos], cursor);
		cursor += (*cmd)->szchar[(*cmd)->pos];
		(*cmd)->pos++;
		i++;
	}
	set_command(cmd);
}

int				handle_normal(char *buf)
{
	int			n;
	int			ret;
	t_command	**cmd;

	recreate(ft_strlen(buf));
	ft_termstr("cd");
	n = command_insert(buf);
	ret = n;
	n = n == 0 ? ft_strlen(buf) : n - 1;
	cmd = ft_getcommand();
	buf_in_stream(n);
	rewrite_end();
	return (ret);
}
