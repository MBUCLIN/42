/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_special.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:31:00 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/25 14:50:51 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void		save_and_retrieve_cursor(char *buf, t_command **cmd)
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

static void		moove_stnd(char *buf, t_command **cmd)
{
	if (buf[2] == 72)
	{
		moove_start(get_cursor(LOCAT, NONE, cmd), (*cmd)->plen);
		(*cmd)->pos = 0;
	}
	else
	{
		moove_end(*cmd);
		(*cmd)->pos = (*cmd)->len;
	}
}

static void		clear_sreen(t_command **cmd)
{
	int			li;
	int			co;
	int			pos;

	ft_termstr("cl");
	ft_putstr((*cmd)->prompt);
	pos = (*cmd)->pos;
	(*cmd)->pos = 0;
	rewrite_end(cmd);
	co = get_cursor(LOCAT, CSCOL, cmd);
	li = get_cursor(LOCAT, CSLIN, cmd);
	ft_moovecursor(co, li);
	(*cmd)->pos = pos;
}

static int		get_mask(char *buf)
{
	int		len;

	len = ft_strlen(buf);
	if (len == 3 && buf[2] < 67)
		return (IS_HIST);
	else if ((len == 3 && buf[2] < 70) ||\
			(len == 4 && buf[3] < 67))
		return (IS_MVTRBL);
	else if (len == 3)
		return (IS_MVSTND);
	else if (len == 4)
		return (IS_MVWRD);
	else if (buf[0] == 12)
		return (IS_CLEAR);
	else if (buf[0] < 18)
		return (IS_WRDCP);
	else if (buf[0] < 25)
		return (IS_SCRC);
	return (IS_DEL);
}

void			handle_special(char *buf, t_command **cmd)
{
	int		mask;

	mask = get_mask(buf);
	if (mask == 0)
		handle_del(cmd);
	else if (IF_MVTRBL(mask))
		handle_trbl(buf, cmd);
	else if (IF_MVWRD(mask))
		handle_mvwrd(buf, cmd);
	else if (IF_MVSTND(mask))
		moove_stnd(buf, cmd);
	else if (IF_SCRC(mask))
		save_and_retrieve_cursor(buf, cmd);
	else if (IF_WRDCP(mask))
		handle_wcp(buf, cmd);
	else if (IF_CLEAR(mask))
		clear_sreen(cmd);
//	else if (IF_HIST(mask))
//		handle_history(buf[2] == 65 ? 1 : -1, cmd);
}
