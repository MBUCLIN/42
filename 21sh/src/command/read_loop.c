/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:55:49 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/08 16:31:03 by mbuclin          ###   ########.fr       */
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
			return (2);
		i++;
	}
	return (1);
}

static char			*stget_command(t_command **cmd)
{
	char	*ret;

	ret = NULL;
	(*cmd)->pos = 0;
	(*cmd)->len = 0;
	if ((*cmd)->command == NULL)
		return (ft_strdup(""));
	else
		ret = ft_strdup((*cmd)->command);
	free((*cmd)->command);
	free((*cmd)->szchar);
	(*cmd)->szchar = NULL;
	(*cmd)->command = NULL;
	free((*cmd));
	*cmd = NULL;
	return (ret);
}

static t_command	*create_command(void)
{
	t_command		*cmd;

	cmd = NULL;
	if ((cmd = (t_command *)malloc(sizeof(t_command))) == NULL)
		return (NULL);
	if ((cmd->command = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))) == NULL)
	{
		free(cmd);
		return (NULL);
	}
	if ((cmd->szchar = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))) == NULL)
	{
		free(cmd->command);
		free(cmd);
		return (NULL);
	}
	ft_bzero(cmd->command, BUF_SIZE + 1);
	ft_bzero(cmd->szchar, BUF_SIZE + 1);
	cmd->pos = 0;
	cmd->len = 0;
	set_command(&cmd);
	return (cmd);
}

char				*read_loop(void)
{
	char		buf[7];
	t_command	*cmd;

	ft_memset(buf, 0, 7);
	ft_putstr("$> ");
	ft_changesignal(0, 0, NULL);
	if ((cmd = create_command()) == NULL)
		return (NULL);
	while (42)
	{
		if (read(0, buf, 6) < 1)
			break ;
		if (buf[0] == '\n' && !buf[1])
			return (stget_command(&cmd));
//		if (check_quotelvl(buf) == 0)
//			return (get_command(&cmd));
		else if (buf[0] == 27 && buf[1] == 0)
			break ;
		if (check_special(buf) == 2)
			handle_special(buf, &cmd);
		else
			handle_normal(buf, &cmd);
		ft_memset(buf, 0, 7);
	}
	return (NULL);
}
