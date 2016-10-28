/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_trbl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 16:18:38 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/28 12:31:43 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void		handle_rightleft(int add, t_command **cmd)
{
	int		n;
	int		col;
	int		cursor;

	if ((add == 0 && (*cmd)->pos == (*cmd)->len) ||\
		(add == -1 && (*cmd)->pos == 0))
		return ;
	n = 0;
	col = get_colsz();
	cursor = get_cursor(LOCAT, cmd);
	while (n != (*cmd)->szchar[(*cmd)->pos + add])
	{
		if (add == -1)
			ft_termstr("le");
		else
			ft_termstr("nd");
		n++;
	}
	if (add == -1)
		(*cmd)->pos--;
	else
		(*cmd)->pos++;
}

void		handle_trbl(char *buf, t_command **cmd)
{
	int		len;

	len = ft_strlen(buf);
	if (len == 3)
	{
		if (buf[len - 1] == 68)
			handle_rightleft(-1, cmd);
		else
			handle_rightleft(0, cmd);
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
