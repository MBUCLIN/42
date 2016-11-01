/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_trbl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 16:18:38 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/31 15:12:33 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void		handle_rightleft(int add, t_command **cmd)
{
	int		n;

	if ((add == 0 && (*cmd)->pos == (*cmd)->len) ||\
		(add == -1 && (*cmd)->pos == 0))
		return ;
	n = -1;
	while (++n != (*cmd)->szchar[(*cmd)->pos + add])
		if (add == -1)
			left_moove(*cmd);
		else
			right_moove(*cmd);
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
