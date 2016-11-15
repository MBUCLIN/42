/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stnd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:59:19 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/15 17:05:21 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void		handle_stnd(char *buf, t_command **cmd)
{
	int		mv;
	int		up;
	int		line_len;

	mv = get_column(get_cursor(LENGT, cmd));
	up = get_line(get_cursor(LOCAT, cmd));
	line_len = get_line(get_cursor(LENGT, cmd));
	if (buf[2] == 72)
	{
		mv = (*cmd)->plen;
		ft_moovecursor(mv, (-up));
		(*cmd)->pos = 0;
	}
	else
	{
		up = line_len - up;
		ft_moovecursor(mv, up);
		(*cmd)->pos = (*cmd)->len;
	}
}
