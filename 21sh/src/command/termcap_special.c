/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:00:35 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/22 15:09:34 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void		delete_char(void)
{
	char		*req;

	if ((req = tgetstr("dm", NULL)) == NULL)
		ft_termstr("dc");
	else
	{
		tputs(req, 1, ft_writechar);
		ft_termstr("dc");
		ft_termstr("ed");
	}
}

void		insert_char(int c)
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

int			left_moove(int cursor, int szchar, t_command *cmd)
{
	int			col;
	int			i;
	int			new_line;

	i = 0;
	col = tgetnum("co");
	if (cmd->command[cmd->pos - 1] == '\n')
	{
		new_line = (cursor - szchar) % col;
		ft_termstr("up");
		while (++i <= new_line)
			ft_termstr("nd");
		return (1);
	}
	if (cursor % col == 0)
	{
		ft_termstr("up");
		while(++i <= (col - szchar))
			ft_termstr("nd");
		return (1);
	}
	else
		ft_termstr("le");
	return (0);
}

void		right_moove(t_command *cmd, int n)
{
	int		cursor;
	int		col;

	cursor = get_cursor(LOCAT, &cmd);
	col = tgetnum("co");
	if ((cursor + n) % col == col - 1)
		ft_termstr("sf");
	else
		ft_termstr("nd");
}
