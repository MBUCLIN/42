/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 13:35:40 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/07 14:45:57 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

char		*read_etcpaths(void)
{
	char		*line;
	char		*paths;
	int			fd;

	line = NULL;
	paths = NULL;
	if ((fd = open("/etc/paths", O_RDONLY)) == -1)
	{
		ft_perror("minishell: file not found", NULL);
		end_minishell(fd);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (paths && (paths = ft_strjoinfree(paths, ":")) == NULL)
			return (NULL);
		if ((paths = ft_strjoindfree(paths, line)) == NULL)
			return (NULL);
		line = NULL;
	}
	return (paths);
}

static char		*get_linecommand(char *line)
{
	char		*afterpart;

	afterpart = NULL;
	if (line)
	{
		if (get_next_line(0, &afterpart) != 1)
			return (NULL);
		if ((line = ft_strjoinfree(line, "\n")) == NULL)
			return (NULL);
		if ((line = ft_strjoindfree(line, afterpart)) == NULL)
			return (NULL);
	}
	else if (line == NULL)
		if (get_next_line(0, &line) != 1)
			return (NULL);
	return (line);
}

char			*read_command(char *line, int n)
{
	if ((line = get_linecommand(line)) == NULL)
		return (NULL);
	if (!ft_isstrascii(line))
		end_minishell(-1);
	n = ft_strnchr(line, '\"');
	if (n == 0)
		return (line);
	else if (n < 0)
		return (NULL);
	else if (n % 2 == 0)
		return (line);
	return (read_command(line, n));
}
