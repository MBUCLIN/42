/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:16:11 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/30 17:05:25 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void		ft_termstr(char *id)
{
	char		*req;

	if ((req = tgetstr(id, NULL)) == NULL)
		return ;
	else
		tputs(req, 1, ft_writechar);
}

void		ft_termgoto(char *id, int c, int l)
{
	char		*req;

	if ((req = tgoto(id, l, c)) == NULL)
		return ;
	else
		tputs(req, 1, ft_writechar);
}

int			left_moove(int cursor, int szchar, t_command *cmd)
{
	int		col;
	int		new_co;

	col = tgetnum("co");
	if (cmd->command[cmd->pos - 1] == '\n')
	{
		new_co = (cursor - szchar) % col;
		ft_moovecursor(new_co, -1);
		return (1);
	}
	if (cursor % col == 0)
	{
		ft_moovecursor((col - szchar), -1);
		return (1);
	}
	ft_termstr("le");
	return (0);
}

void		right_moove(t_command *cmd, int n)
{
	int		cursor;
	int		col;

	cursor = get_cursor(LOCAT, NONE, &cmd);
	col = tgetnum("co");
	if ((cursor + n) % col == col -1)
		ft_moovecursor(0, 1);
	else
		ft_termstr("nd");
}
