/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:04:20 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/28 15:12:59 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void		deleteon_str(char *szchar, char *cmd, t_command **comd)
{
	int		i;

	i = (*comd)->pos;
	
	if (szchar[i] && cmd[i])
	{
		while (cmd[i])
		{
			cmd[i] = cmd[i + 1];
			if (cmd[i] == '\t')
				szchar[i] = get_tabszst(get_cursor(LOCAT, comd));
			else
				szchar[i] = 1;
			i++;
		}
	}
	szchar[i - 1] = 0;
}

void			handle_del(t_command **cmd)
{
	int		n;
	int		oldlen;
	int		sz_char;

	n = 0;
	oldlen = get_cursor(LENGT, cmd) - (*cmd)->szchar[(*cmd)->pos - 1];
	if ((*cmd)->pos == 0)
		return ;
	while (n < (*cmd)->szchar[(*cmd)->pos - 1])
	{
		tputs(tgetstr("le", NULL), 1, ft_writechar);
		delete_char();
		n++;
	}
	(*cmd)->pos -= 1;
	(*cmd)->len -= 1;
	sz_char = (*cmd)->szchar[(*cmd)->pos];
	deleteon_str((*cmd)->szchar, (*cmd)->command, cmd);
	rewrite_end(cmd, 0);
}
