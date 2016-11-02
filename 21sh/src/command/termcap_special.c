/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:00:35 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/02 15:17:42 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void		delete_char(void)
{
	char		*req;

	if ((req = tgetstr("dm", NULL)) == NULL)
		ft_termstr("dc");
	else
	{
		tputs(req, 1, ft_writechar);
		ft_termstr("dc");
		ft_termstr("ed");
	}
}

void		insert_char(int c)
{
	char		*req;

	if ((req = tgetstr("im", NULL)) == NULL)
	{
		if ((req = tgetstr("ic", NULL)) == NULL)
			write(1, &c, 1);
		else
		{
			tputs(req, 1, ft_writechar);
			write(1, &c, 1);
		}
	}
	else
	{
		tputs(req, 1, ft_writechar);
		if ((req = tgetstr("ic", NULL)) == NULL)
			write(1, &c, 1);
		else
		{
			tputs(req, 1, ft_writechar);
			write(1, &c, 1);
		}
		ft_termstr("ei");
	}
}

void		left_moove(int cursor)
{
	int			col;
	int			i;

	i = 0;
	col = get_colsz();
	if (cursor % col == 0)
	{
		ft_termstr("up");
		while(++i < col)
			ft_termstr("nd");
	}
	else
		ft_termstr("le");
}

void		right_moove(t_command *cmd)
{
	int		cursor;
	int		col;

	cursor = get_cursor(LOCAT, &cmd);
	col = get_colsz();
	if (cursor % col == col - 1)
		ft_termstr("sf");
	else
		ft_termstr("nd");
}
