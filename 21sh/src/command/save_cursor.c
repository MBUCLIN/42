/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:12:44 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/24 15:06:59 by mbuclin          ###   ########.fr       */
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
	int		up;

	save = save_cursorpos(-1);
	up = get_line(cursor) - get_line(save);
	if (get_column(cursor) == 0 && up)
		ft_moovecursor(get_column(save), -(up - 1));
	else
		ft_moovecursor(get_column(save), -(up));
	return (save);
}
