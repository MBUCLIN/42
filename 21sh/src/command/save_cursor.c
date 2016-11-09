/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:12:44 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/09 17:10:43 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			save_cursorpos(int cursor)
{
	static int	save = 0;

	if (cursor >= 0)
		save = cursor;
	return (save);
}

int			retr_cursorpos(int cursor)
{
	int		save;
	int		col;
	int		up;
	int		mv;

	save = save_cursorpos(-1);
	col = tgetnum("co");
	up = (cursor / col) - (save / col);
	mv = save % col;
	ft_termstr("cr");
	if (cursor % col == 0 && up)
		up--;
	while (up)
		if (up > 0)
		{
			ft_termstr("up");
			up--;
		}
		else
		{
			ft_termstr("do");
			up++;
		}
	while (mv)
	{
		ft_termstr("nd");
		mv--;
	}
	return (save);
}
