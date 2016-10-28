/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 12:12:44 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/28 12:15:16 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void		init_savecursor(void)
{
	char		*req;

	if ((req = tgetstr("sr", NULL)) == NULL)
		return ;
	tputs(req, 1, ft_writechar);
}
