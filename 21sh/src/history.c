/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:47:48 by mbuclin           #+#    #+#             */
/*   Updated: 2016/12/01 16:38:14 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static char		*ft_escapend(char *command)
{
	char		*ret;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if ((ret = (char *)ft_memalloc(sizeof(char) * (ft_strlen(command) +\
								ft_strccnt(command, '\n') + 2))) == NULL)
		return (NULL);
	while (command[i])
	{
		if (command[i] == '\n')
		{
			ret[j] = '\\';
			ret[j + 1] = 'n';
			j += 2;
		}
		else
			ret[j] = command[i];
		j++;
		i++;
	}
	ret[j] = '\n';
	return (ret);
}
void			history_file_save(char *command)
{
	int				fd;
	char			*path;

	if ((path = ft_creadir(ft_gethome(), HISTORY_FILE)) == NULL)
		ft_exitshell("21sh", ERRMALLOC, NULL);
	if ((fd = open(path, O_CREAT | O_RDWR | O_APPEND)) < 0)
		sherror("21sh", ERRFILEOPEN, path);
	command = ft_escapend(command);
	write(1, command, ft_strlen(command));
	write(fd, command, ft_strlen(command));
}
