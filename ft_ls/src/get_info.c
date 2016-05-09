/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 14:35:36 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/09 14:06:16 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*get_spec_right(char *line, int mode)
{
	if (line[3] == '-' && (mode & 04000))
		line[3] = 'S';
	else if (line[3] != '-' && (mode & 04000))
		line[3] = 's';
	if (line[6] == '-' && (mode & 02000))
		line[6] = 'S';
	else if (line[6] != '-' && (mode & 02000))
		line[6] = 's';
	if (line[9] == '-' && (mode & 01000))
		line[9] = 'T';
	else if (line[9] != '-' && (mode & 01000))
		line[9] = 't';
	return (line);
}

char	*get_line_mode(int mode)
{
	char	*line;

	if (!(line = ft_strnew(10)))
		return (NULL);
	line[0] = get_filetype(mode);
	get_right(line + 1, mode, 0100);
	get_right(line + 4, mode, 010);
	get_right(line + 7, mode, 01);
	line = get_spec_right(line, mode);
	return (line);
}

int		get_time(struct stat buf, int timeopt, int t)
{
	if (timeopt == 1)
	{
		if (t == 0)
			return (buf.st_atimespec.tv_sec);
		else
			return (buf.st_atimespec.tv_nsec);
	}
	else if (timeopt == 2)
		return (0);
	if (t == 0)
		return (buf.st_mtimespec.tv_sec);
	return (buf.st_mtimespec.tv_nsec);
}

char	*get_group_name(gid_t gid)
{
	struct group	*group_info;

	if (!(group_info = getgrgid(gid)))
		return (NULL);
	return (ft_strdup(group_info->gr_name));
}

char	*get_user_name(uid_t uid)
{
	struct passwd		*user_info;

	if (!(user_info = getpwuid(uid)))
		return (NULL);
	return (ft_strdup(user_info->pw_name));
}
