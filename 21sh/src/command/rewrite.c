/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 11:59:11 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/28 14:54:26 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void		delete_end(int pos, int len)
{
	while (pos < len)
	{
		delete_char();
		pos++;
	}
}

void			rewrite_end(t_command **cmd, int insert)
{
	int		pos;
	int		len;
	int		size;
	int		c;

	ft_termstr("sc");
	len = (*cmd)->len;
	pos = (*cmd)->pos;
	delete_end(get_cursor(LOCAT, cmd), get_cursor(LENGT, cmd));
	while (pos < len)
	{
		c = (*cmd)->command[pos] == '\t' ? '.' : (*cmd)->command[pos];
		size = (*cmd)->szchar[pos];
		while (size)
		{
			if (insert)
				insert_char(c);
			else
				write(1, &c, 1);
			size--;
		}
		pos++;
	}
	ft_termstr("rc");
}
