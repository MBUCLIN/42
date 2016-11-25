/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:12:44 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/25 14:04:26 by mbuclin          ###   ########.fr       */
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
	int		li;
	int		col;

	col = tgetnum("co");
	save = save_cursorpos(-1);
	li = (cursor / col) - (save / col);
	if ((cursor % col) == 0 && li)
		ft_moovecursor(save % col, -(li - 1));
	else
		ft_moovecursor(save % col, -(li));
	return (save);
}
