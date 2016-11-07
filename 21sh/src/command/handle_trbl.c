/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_trbl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 16:18:38 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/07 16:13:49 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void		handle_rightleft(int add, t_command **cmd)
{
	int		n;
	int		szchar;

	if ((add == 0 && (*cmd)->pos == (*cmd)->len) ||\
		(add == -1 && (*cmd)->pos == 0))
		return ;
	n = -1;
	while (++n != (szchar = (*cmd)->szchar[(*cmd)->pos + add]))
		if (add == -1)
		{

			if (left_moove(get_cursor(LOCAT, cmd), szchar) == 1)
				break ;
		}
		else
			right_moove(*cmd, n);
	if (add == -1)
		(*cmd)->pos--;
	else
		(*cmd)->pos++;
	set_command(cmd);
}

void			handle_trbl(char *buf, t_command **cmd)
{
	int		len;

	len = ft_strlen(buf);
	if (len == 3)
	{
		if (buf[len - 1] == 68)
		{
			handle_rightleft(-1, cmd);
		}
		else
		{
			handle_rightleft(0, cmd);
		}
	}
/*
	else
	{
		if (buf[len - 1] == 65)
			handle_updown(-1, cmd);
		else
			handle_updown(1, cmd);
	}
*/
}
