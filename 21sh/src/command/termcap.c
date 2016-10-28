/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:16:11 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/28 14:04:58 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void		ft_termstr(char *id)
{
	char		*req;

	if ((req = tgetstr(id, NULL)) == NULL)
		return ;
	else
		tputs(req, 1, ft_writechar);
}

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
	char	*req;
	
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
		write(1, &c, 1);
		ft_termstr("ei");
	}
}
