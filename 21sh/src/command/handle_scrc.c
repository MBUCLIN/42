/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_scrc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:47:37 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/24 14:14:27 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void		handle_scrc(char *buf, t_command **cmd)
{
	static int		savedpos = -1;

	if (buf[0] == 24)
	{
		ft_termstr("sc");
		savedpos = (*cmd)->pos;
	}
	else if (savedpos != -1)
	{
		ft_termstr("rc");
		(*cmd)->pos = savedpos;
		savedpos = -1;
	}
}
