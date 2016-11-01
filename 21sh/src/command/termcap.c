/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:16:11 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/31 15:06:35 by mbuclin          ###   ########.fr       */
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

void		ft_termgoto(char *id, int c, int l)
{
	char		*req;

	if ((req = tgoto(id, l, c)) == NULL)
		return ;
	else
		tputs(req, 1, ft_writechar);
}
