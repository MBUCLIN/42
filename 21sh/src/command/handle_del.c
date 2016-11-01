/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:04:20 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/01 12:09:07 by mbuclin          ###   ########.fr       */
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
				szchar[i] = get_tabszst(get_cursor(LOCAT, comd));
			else
				szchar[i] = 1;
			i++;
			(*comd)->pos = i;
		}
	}
	(*comd)->pos = pos;
}

void			handle_del(t_command **cmd)
{
	int			cursor;
	int			col;
	int			szchar;

	if ((*cmd)->pos == 0)
		return ;
	col = get_colsz();
	cursor = get_cursor(LOCAT, cmd);
	szchar = (*cmd)->szchar[(*cmd)->pos];
	while (szchar)
	{
		left_moove(*cmd);
		if (cursor % col == 0)
			ft_termstr("ce");
		delete_char();
		szchar--;
	}
	(*cmd)->pos--;
	(*cmd)->len--;
	deleteon_str((*cmd)->szchar, (*cmd)->command, cmd);
	rewrite_end(cmd);
}
