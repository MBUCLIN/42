/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:05:27 by lgosse            #+#    #+#             */
/*   Updated: 2015/12/28 17:18:47 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_proto.h"

char		**ft_treat_read(char *read_result)
{
	char	**sample;

	if (ft_check_empty_lines(read_result) == 1)
	{
		sample = ft_strsplit(read_result, '\n');
		ft_strdel(&read_result);
		if (ft_is_sample_valid(sample) != 1)
		{
			ft_putendl("error2");
			return (NULL);
		}
		else
		{
			return (sample);
		}
	}
	return (NULL);
}

char		**ft_read_sample(char *filename)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*read_result;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	read_result = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(read_result, buf);
		free(read_result);
		read_result = tmp;
	}
	if (close(fd) == -1)
		ft_putstr("close() error");
	if (!read_result || ft_check_splitted(read_result) != 1)
	{
		ft_putendl("error 3");
		return (NULL);
	}
	return (ft_treat_read(read_result));
}

int		ft_check_splitted(char *read)
{
	int i;

	i = -1;
	while (read[++i])
	{
		if (read[i] == '\n' && read[i + 1] == '\n' && read[i + 2] == '\n')
			return (0);
		else if (read[i] == '\n' && read[i + 1] == '\n' && read[i + 2] == '\0')
			return (0);
	}
	return (1);
}
