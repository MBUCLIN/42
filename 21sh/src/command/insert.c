/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:41:51 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/22 15:56:40 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void			insert_end(t_command **cmd, char *buf, int cursor)
{
	int		i;
	int		col;

	i = 1;
	col = tgetnum("co");
	moove_end(cursor, *cmd);
	cursor = get_cursor(LENGT, cmd);
	write(1, buf, 1);
	(*cmd)->command[(*cmd)->len] = '\n';
	(*cmd)->szchar[(*cmd)->len] = cursor % col;
	(*cmd)->len++;
	(*cmd)->pos = (*cmd)->len;
}

void			inserton_str(t_command **cmd, int len)
{
	char		*sub;
	int			j;
	int			save;

	save = (*cmd)->pos;
	j = 0;
	sub = NULL;
	if ((sub = ft_strsub(((*cmd)->command + (*cmd)->pos),\
				0, ft_strlen(((*cmd)->command + (*cmd)->pos)))) == NULL)
		ft_exitshell("21sh", ERRMALLOC, NULL);
	(*cmd)->pos += len;
	while (sub[j])
	{
		(*cmd)->command[(*cmd)->pos] = sub[j];
		if (sub[j] == '\t')
			(*cmd)->szchar[(*cmd)->pos] = get_tabszst(get_cursor(LOCAT, cmd));
		else
			(*cmd)->szchar[(*cmd)->pos] = 1;
		j++;
		(*cmd)->pos++;
	}
	(*cmd)->pos = save;
	free(sub);
}

static int		insert_tab(t_command **cmd, int cursor, char *buf)
{
	int			szchar;

	(*cmd)->len++;
	(*cmd)->pos++;
	(*cmd)->command[(*cmd)->pos - 1] = '\t';
	szchar = get_tabszst(cursor);
	(*cmd)->szchar[(*cmd)->pos - 1] = szchar;
	ft_memset(buf, '.', szchar);
	return (1);
}

int				insert_buf(t_command **cmd, char *buf, int cursor, int len)
{
	int		i;

	i = 0;
	if (buf[0] == '\t' && ft_strlen(buf) == 1)
	{
		return (insert_tab(cmd, cursor, buf));
	}
	while (i < len)
	{
		buf[i] = buf[i] <= 31 ? '[' : buf[i];
		buf[i] = buf[i] >= 127 ? '~' : buf[i];
		(*cmd)->command[(*cmd)->pos] = buf[i];
		(*cmd)->szchar[(*cmd)->pos] = 1;
		(*cmd)->pos++;
		(*cmd)->len++;
		cursor++;
		i++;
	}
	return (1);
}
