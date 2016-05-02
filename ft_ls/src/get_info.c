/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 14:35:36 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/02 16:30:53 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*get_line_mode(int mode)
{
	char	*line;

	if (!(line = ft_strnew(10)))
		return (NULL);
	line[0] = get_filetype(mode);
	get_right(line + 1, mode, 0100);
	get_right(line + 4, mode, 010);
	get_right(line + 7, mode, 01);
	return (line);
}

int		get_time(struct stat buf, int timeopt)
{
	time_t		the_time;

	ft_printf("%d : time option\n", timeopt);
	if (timeopt == 1)
		return (buf.st_atimespec.tv_sec);
	else if (timeopt == 2)
		return (time(&the_time));
	return (buf.st_mtimespec.tv_sec);
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
