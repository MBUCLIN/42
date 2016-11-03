/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 11:59:11 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/03 15:54:33 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void			delete_end(int pos, int len, char *szchar)
{
	int		i;

	ft_termstr("cd");
	while (pos < len)
	{
		i = 0;
		while (i < szchar[pos])
		{
			delete_char();
			i++;
		}
		pos++;
	}
}

static t_command	**set_command(t_command **cmd)
{
	static t_command		*saved = NULL;

	if (cmd == NULL)
		return (&saved);
	else
		&saved = cmd;
	return (cmd);
}

t_command			**get_command(void)
{
	return (set_command(NULL));
}

void				rewrite_end(t_command **cmd)
{
	int		pos;
	int		size;
	int		c;
	int		len;
	
	set_command(cmd);
	len = (*cmd)->len;
	pos = (*cmd)->pos;
	delete_end((*cmd)->pos, len, (*cmd)->szchar);
	ft_termstr("sc");
	while ((*cmd)->pos < len)
	{
		c = (*cmd)->command[(*cmd)->pos] == '\t' ?\
				'.' : (*cmd)->command[(*cmd)->pos];
		size = (*cmd)->command[(*cmd)->pos] == '\t' ?\
			   get_tabszst(get_cursor(LOCAT, cmd)) : 1;
		while (size)
		{
			write(1, &c, 1);
			size--;
		}
		(*cmd)->pos++;
	}
	(*cmd)->pos = pos;
	ft_termstr("rc");
}
