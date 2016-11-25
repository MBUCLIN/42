/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:55:49 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/25 14:56:18 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int			check_special(char *buf)
{
	static int		special[TABLEN][6] = {HISTN, HISTP, MVOUP, MVODO, MVOLFT,\
										MVORGT, MVWLFT, MVWRGT, MVST, MVND,\
										WCUT, WPST, SCUR, RCUR, BCLR, CDEL};
	int				i;

	i = 0;
	while (i < TABLEN)
	{
		if (special[i][0] == buf[0] &&\
			special[i][1] == buf[1] &&\
			special[i][2] == buf[2] &&\
			special[i][3] == buf[3] &&\
			special[i][4] == buf[4] &&\
			special[i][5] == buf[5])
			return (1);
		i++;
	}
	return (0);
}

static t_command	*initialize_loop(char *prompt, int mask, char *command)
{
	t_command		*cmd;

	if (!mask)
		ft_changesignal(0, 0, NULL);
	if ((cmd = create_command(prompt, mask, command)) == NULL)
		ft_exitshell("21sh", ERRMALLOC, NULL);
	set_command(&cmd);
	ft_putstr(cmd->prompt);
	return (cmd);
}

static t_command	*caller_loop(int mask, char *remain)
{
	remain = *remain == 0 ? NULL : remain;
	if (mask & QTE)
		return (read_loop("quote> ", mask, remain));
	return (read_loop("dquote> ", mask, remain));
}

static int			redirect_buffer(char *buf, t_command **cmd, int check)
{
	int			insret;
	t_command	*qte;

	if (check == 1)
		handle_special(buf, cmd);
	else
	{
		if ((insret = handle_normal(buf, cmd)) > 0)
		{
			if ((*cmd)->qmask != 0)
				qte = caller_loop((*cmd)->qmask, buf + insret);
			else
				return (1);
			recreate(qte->len);
			ft_strcpy(((*cmd)->command + (*cmd)->len), qte->command);
			ft_strcpy(((*cmd)->szchar + (*cmd)->len), qte->szchar);
			(*cmd)->len += qte->len;
			del_command(qte);
			qte = NULL;
			return (1);
		}
	}
	return (0);
}

t_command			*read_loop(char *prompt, int mask, char *command)
{
	char		buf[7];
	t_command	*cmd;
	int			end;

	ft_memset(buf, 0, 7);
	cmd = initialize_loop(prompt, mask, command);
	while (42)
	{
		if (read(0, buf, 6) < 1)
			break ;
		if ((end = redirect_buffer(buf, &cmd, check_special(buf))) == 1)
			return (cmd);
		ft_memset(buf, 0, 7);
	}
	del_command(cmd);
	return (NULL);
}
