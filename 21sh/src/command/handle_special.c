/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_special.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:31:00 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/14 11:39:25 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

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
		handle_stnd(buf, cmd);
	else if (IF_SCRC(mask))
		handle_scrc(buf, cmd);
	else if (IF_WRDCP(mask))
		handle_wcp(buf, cmd);
}
