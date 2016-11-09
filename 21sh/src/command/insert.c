/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:41:51 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/08 16:16:09 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

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
		exit(1);
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

static int		insert_tab(t_command **cmd, int col, int cursor, char *buf)
{
	int			szchar;
	int			sf;

	sf = 0;
	(*cmd)->len++;
	(*cmd)->pos++;
	(*cmd)->command[(*cmd)->pos - 1] = '\t';
	szchar = get_tabszst(cursor);
	(*cmd)->szchar[(*cmd)->pos - 1] = szchar;
	if ((cursor + szchar) % col == 0)
		sf = 1;
	ft_memset(buf, '.', szchar);
	return (sf);

}

int				insert_buf(t_command **cmd, char *buf, int cursor)
{
	int		col;
	int		i;
	int		sf;

	col = tgetnum("co");
	i = 0;
	sf = 0;
	if (buf[0] == '\t' && ft_strlen(buf) == 1)
	{
		return (insert_tab(cmd, col, cursor, buf));
	}
	while (buf[i])
	{
		buf[i] = buf[i] <= 31 ? '[' : buf[i];
		buf[i] = buf[i] >= 127 ? '~' : buf[i];
		(*cmd)->command[(*cmd)->pos] = buf[i];
		(*cmd)->szchar[(*cmd)->pos] = 1;
		(*cmd)->pos++;
		(*cmd)->len++;
		cursor++;
		if (cursor % col == 0)
			sf = 1;
		i++;
	}
	return (sf);
}
