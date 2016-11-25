/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:45:54 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/25 17:46:01 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int		ft_lenbuf(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	return (i);
}

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

	col = tgetnum("co");
	while (size)
	{
		if (cursor >= 0)
		{
			insert_char(c);
			if ((cursor + 1) % col == 0)
				ft_moovecursor(0, 1);
		}
		else
			write(1, &c, 1);
		size--;
	}
}

static int		insert_buffer(char *buf, int cursor, t_command **cmd)
{
	int		i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		check_quotelvl(buf[i]);
		display_char(buf[i], (*cmd)->szchar[(*cmd)->pos], cursor);
		i++;
		cursor++;
		(*cmd)->pos++;
	}
}

int				handle_normal(char *buf, t_command **cmd)
{
	int			n;

	recreate(ft_strlen(buf));
	n = command_insert_buffer();

//	insert_buffer(buf, cursor);
//	rewrite_end(cmd);
//	set_command(cmd);
	return (n);
}
