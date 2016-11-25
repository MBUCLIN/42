/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:04:20 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/25 14:41:36 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void		deleteon_str(char *szchar, char *cmd, t_command **comd)
{
	int		i;
	int		pos;

	i = (*comd)->pos;
	pos = (*comd)->pos;
	if (cmd[i])
	{
		while (cmd[i])
		{
			cmd[i] = cmd[i + 1];
			if (cmd[i] == '\t')
				szchar[i] = get_tabszst(get_cursor(LOCAT, NONE, comd));
			else
				szchar[i] = 1;
			i++;
			(*comd)->pos = i;
		}
	}
	(*comd)->pos = pos;
}

void			delete_char(void)
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

void			handle_del(t_command **cmd)
{
	int			cursor;
	int			szchar;

	if ((*cmd)->pos == 0)
		return ;
	cursor = get_cursor(LOCAT, NONE, cmd);
	szchar = (*cmd)->szchar[(*cmd)->pos - 1];
	check_quotelvl((*cmd)->command[(*cmd)->pos - 1]);
	while (szchar)
	{
		left_moove(cursor, szchar, *cmd);
		delete_char();
		szchar--;
		cursor--;
	}
	(*cmd)->pos--;
	(*cmd)->len--;
	deleteon_str((*cmd)->szchar, (*cmd)->command, cmd);
	rewrite_end(cmd);
}
