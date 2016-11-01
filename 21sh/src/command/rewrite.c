/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 11:59:11 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/31 17:36:56 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void		delete_end(int pos, int len, char *szchar)
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

void			rewrite_end(t_command **cmd)
{
	int		pos;
	int		len;
	int		size;
	int		c;

	len = (*cmd)->len;
	pos = (*cmd)->pos;
	delete_end(pos, len, (*cmd)->szchar);
	ft_termstr("sc");
	while (pos < len)
	{
		c = (*cmd)->command[pos] == '\t' ? '.' : (*cmd)->command[pos];
		size = (*cmd)->szchar[pos];
		while (size)
		{
			write(1, &c, 1);
			size--;
		}
		pos++;
	}
	ft_termstr("rc");
}
