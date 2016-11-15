/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:45:54 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/15 16:04:53 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int		ft_lenbuf(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		i++;
	}
	return (i);
}

static int		insert_buffer(char *buf, int cursor)
{
	int		col;
	int		n;
	int		len;

	col = tgetnum("co");
	len = ft_lenbuf(buf);
	n = 0;
	while (n < len)
	{
		check_quotelvl(buf[n]);
		insert_char(buf[n]);
		cursor++;
		n++;
		if (cursor % col == 0)
			ft_termstr("sf");
	}
	return (n);
}

int				handle_normal(char *buf, t_command **cmd)
{
	int			n;
	int			cursor;
	int			tabu;
	size_t		len;

	tabu = buf[0] == '\t' ? 1 : 0;
	len = ft_lenbuf(buf);
	recreate(cmd, ft_strlen(buf));
	inserton_str(cmd, len);
	cursor = get_cursor(LOCAT, cmd);
	insert_buf(cmd, buf, cursor, len);
	n = insert_buffer(buf, cursor);
	rewrite_end(cmd);
	set_command(cmd);
	if (len < ft_strlen(buf) && !tabu)
	{
		check_quotelvl(buf[len]);
		insert_end(cmd, buf + len, cursor);
		return (len + 1);
	}
	return (0);
}
