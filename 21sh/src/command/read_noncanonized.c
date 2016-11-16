/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_noncanonized.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:06:01 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/16 15:14:53 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int		quoting_level(char *line)
{
	int				i;
	static int		quote[2] = {0, 0};

	i = 0;
	while (line[i])
	{
		if (quote[0] == 1 && line[i] == '\'' &&\
			(i == 0 || line[i - 1] != '\\'))
			quote[0] = 0;
		else if (quote[1] == 1 && line[i] == '"' &&\
				(i == 0 || line[i - 1] != '\\'))
			quote[1] = 0;
		else if (line[i] == '\'' && quote[1] == 0 &&\
				(i == 0 || line[i - 1] != '\\'))
			quote[0] = 1;
		else if (line[i] == '"' && quote[0] == 0 &&\
				(i == 0 || line[i - 1] == '\\'))
			quote[1] = 1;
		i++;
	}
	if (quote[0] || quote[1])
		return (1);
	return (0);
}

static char		*get_cmdline(void)
{
	char		buf[BUF_SIZE + 1];
	char		*line;
	int			ret;

	ft_memset(buf, 0, BUF_SIZE + 1);
	line = NULL;
	while ((ret = read(0, buf, BUF_SIZE)) >= 0)
	{
		if ((line = ft_strjoinfree(line, buf)) == NULL)
			return (NULL);
		ft_memset(buf, 0, BUF_SIZE + 1);
		if (ft_strchr(line, '\n') || ret == 0)
		{
			ft_putendl("read got \\n");
			ft_putendl(line);
			return (line);
		}
	}
	ft_putendl("here");
	sherror("12sh", ERRSTREAM, NULL);
	return (NULL);
}

static char			*readnon_canon(void)
{
	char		*line;
	char		*ret;

	line = NULL;
	ret = NULL;
	if ((line = get_cmdline()) == NULL)
		return (NULL);
	ft_printf("|%s| : line after cmd line\n", line);
	if (quoting_level(line) == 1)
	{
		ft_putendl("quoting on");
		if ((ret = readnon_canon()) == NULL)
			return (NULL);
		if ((line = ft_strjoindfree(line, ret)) == NULL)
		{
			sherror("21sh", ERRMALLOC, NULL);
			exit(-1);
		}
	}
	return (line);
}

char				*init_noncanon_read(void)
{
	char		*command;

	command = NULL;
	ft_putstr("$> ");
	command = readnon_canon();
	ft_printf("|%s| : command\n", command);
	sleep(2);
	return (command);
}
