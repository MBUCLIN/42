/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:05:27 by lgosse            #+#    #+#             */
/*   Updated: 2015/12/17 14:16:29 by lgosse           ###   ########.fr       */
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
			ft_putendl("error");
			return (NULL);
		}
		else
			return (sample);
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
	return (ft_treat_read(read_result));
}
