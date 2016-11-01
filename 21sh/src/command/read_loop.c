/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:55:49 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/31 16:10:52 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int			check_special(char *buf)
{
	static int		special[TABLEN][6] = KEYTAB;
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
	if (ft_strlen(buf) > 1)
		return (0);
	else if ((buf[0] <= 31 || buf[0] >= 127) &&\
			(buf[0] != '\t' && buf[0] != '\n'))
		return (0);
	return (1);
}

static char			*get_command(t_command **cmd)
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
		return (NULL);
	if ((cmd->szchar = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))) == NULL)
		return (NULL);
	ft_bzero(cmd->command, BUF_SIZE + 1);
	ft_bzero(cmd->szchar, BUF_SIZE + 1);
	cmd->pos = 0;
	cmd->len = 0;
	return (cmd);
}

char				*read_loop(void)
{
	char		buf[7];
	t_command	*cmd;
	int			type;

	ft_memset(buf, 0, 7);
	ft_putstr("$> ");
	if ((cmd = create_command()) == NULL)
		return (NULL);
	while (read(0, buf, 6) > 0)
	{
		if (buf[0] == '\n' && !buf[1])
			return (get_command(&cmd));
		else if (buf[0] == 27 && buf[1] == 0)
			return (NULL);
		if ((type = check_special(buf)) == 2)
			handle_special(buf, &cmd);
		if (type == 1)
			handle_normal(buf[0], &cmd);
		ft_memset(buf, 0, 7);
	}
	ft_putendl("NULL read");
	return (NULL);
}
