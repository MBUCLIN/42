/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:45:54 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/07 16:55:53 by mbuclin          ###   ########.fr       */
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

static char		*inserton_str(char *szchar, char *cmd, t_command **comd, int len)
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
	(*comd)->pos += len;
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

static int		insert_buf(t_command **cmd, char *buf, int cursor)
{
	int		i;
	int		sf;
	int		col;

	i = 0;
	sf = 0;
	col = tgetnum("co");
	if (buf[0] == '\t' && ft_strlen(buf) == 1)
	{
		(*cmd)->len++;
		(*cmd)->pos++;
		(*cmd)->command[(*cmd)->pos - 1] = '\t';
		(*cmd)->szchar[(*cmd)->pos - 1] = get_tabszst(cursor);
		if ((cursor + (*cmd)->szchar[(*cmd)->pos - 1]) % col == 0)
			sf = 1;
		ft_memset(buf, '.', (*cmd)->szchar[(*cmd)->pos - 1]);
	}
	else
		while (buf[i])
		{
			(*cmd)->command[(*cmd)->pos] = buf[i];
			(*cmd)->command[(*cmd)->pos] = 1;
			(*cmd)->pos++;
			(*cmd)->len++;
			if ((cursor + 1) % col == 0)
				sf = 1;
			i++;
		}
	return (sf);
}
void			handle_normal(char *buf, t_command **cmd)
{
	int			n;
	int			col;
	int			sf;
	int			cursor;

	col = tgetnum("co");
	recreate(cmd, ft_strlen(buf));
	inserton_str((*cmd)->szchar, (*cmd)->command, cmd, ft_strlen(buf));
	cursor = get_cursor(LOCAT, cmd);
	sf = insert_buf(cmd, buf, cursor);
	n = 0;
	while (buf[n])
	{
		insert_char(buf[n]);
		n++;
	}
	if (sf)
		ft_termstr("sf");
	rewrite_end(cmd);
}
