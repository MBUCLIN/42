/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:45:54 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/02 15:17:33 by mbuclin          ###   ########.fr       */
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
	int			mask;

	mask = get_mask(buf);
	if (mask == 0)
		handle_del(cmd);
	else if (IF_MVTRBL(mask))
	{
		handle_trbl(buf, cmd);
	}
}

static char		*inserton_str(char *szchar, char *cmd, t_command **comd)
{
	char		*sub;
	int			j;
	int			save;

	save = (*comd)->pos;
	j = 0;
	sub = NULL;
	if ((sub = ft_strsub(cmd + (*comd)->pos,\
						0, ft_strlen(cmd + (*comd)->pos))) == NULL)
		return (NULL);
	(*comd)->pos++;
	while (sub[j])
	{
		cmd[(*comd)->pos] = sub[j];
		if (sub[j] == '\t')
			szchar[(*comd)->pos] = get_tabszst(get_cursor(LOCAT, comd));
		else
			szchar[(*comd)->pos] = 1;
		j++;
		(*comd)->pos++;
	}
	(*comd)->pos = save;
	free(sub);
	return (cmd);
}

void			handle_normal(int c, t_command **cmd)
{
	int			n;
	int			col;
	int			sf;
	int			cursor;

	sf = 0;
	col = get_colsz();
	recreate(cmd);
	inserton_str((*cmd)->szchar, (*cmd)->command, cmd);
	cursor = get_cursor(LOCAT, cmd);
	(*cmd)->command[(*cmd)->pos] = c;
	(*cmd)->szchar[(*cmd)->pos] = 1;
	(*cmd)->pos++;
	(*cmd)->len++;
	if ((cursor + 1) % col == 0)
		sf = 1;
	if (c == '\t')
	{
		(*cmd)->szchar[(*cmd)->pos - 1] = get_tabszst(cursor);
		if ((cursor + (*cmd)->szchar[(*cmd)->pos - 1]) % col == 0)
			sf = 1;
		c = '.';
	}
	n = 0;
	while (n < (*cmd)->szchar[(*cmd)->pos - 1])
	{
		
		insert_char(c);
		n++;
	}
	if (sf)
		ft_termstr("sf");
	rewrite_end(cmd);
}
