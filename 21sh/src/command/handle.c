/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:45:54 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/28 16:15:52 by mbuclin          ###   ########.fr       */
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
		handle_trbl(buf, cmd);
}

static char		*inserton_str(char *szchar, char *cmd, t_command **comd)
{
	char		*sub;
	int			i;
	int			j;
	int			save;

	i = (*comd)->pos;
	save = i;
	j = 0;
	sub = NULL;
	if ((sub = ft_strsub(cmd + i, 0, ft_strlen(cmd + i))) == NULL)
		return (NULL);
	while (++i <= (*comd)->len)
	{
		(*comd)->pos = i;
		cmd[i] = sub[j];
		if (cmd[i] == '\t')
			szchar[i] = get_tabszst(get_cursor(LOCAT, comd));
		else
			szchar[i] = 1;
		j++;
	}
	(*comd)->pos = save;
	free(sub);
	return (cmd);
}
void			handle_normal(int c, t_command **cmd)
{
	int			n;


	if ((*cmd)->len != 0 && (*cmd)->len % BUF_SIZE == 0)
	{
		ft_printf("create");
		if (((*cmd)->command = recreate_command((*cmd)->command)) == NULL)
			exit(1);
		if (((*cmd)->szchar = recreate_szchar((*cmd)->szchar)) == NULL)
			exit(1);
	}
	inserton_str((*cmd)->szchar, (*cmd)->command, cmd);
	(*cmd)->command[(*cmd)->pos] = c;
	(*cmd)->szchar[(*cmd)->pos] = 1;
	n = -1;
	if (c == '\t')
	{
		(*cmd)->szchar[(*cmd)->pos] = get_tabszst(get_cursor(LOCAT, cmd));
		c = '.';
	}
	while (++n < (*cmd)->szchar[(*cmd)->pos])
		insert_char(c);
	(*cmd)->pos++;
	(*cmd)->len++;
	rewrite_end(cmd, 1);
}
