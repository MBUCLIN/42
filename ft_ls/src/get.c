/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 15:55:44 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/10 16:23:20 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*get_date_year(time_t tfile)
{
	char		*timec;
	char		*ret;

	if (!(timec = ctime(&tfile)))
		return (NULL);
	if (!(ret = ft_strsub(timec, 4, 6)))
		return (NULL);
	if (!(ret = ft_strncadd(ret, 2, ' ')))
		return (NULL);
	return (ft_strjoindfree(ret, ft_strsub(timec, 20, 4)));
}

char		*get_date(time_t tfile)
{
	char		*timec;

	if (!(timec = ctime(&tfile)))
		return (NULL);
	return (ft_strsub(timec, 4, 12));
}

char		get_filetype(int mode)
{
	if (S_ISFIFO(mode))
		return ('p');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISREG(mode))
		return ('-');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISSOCK(mode))
		return ('s');
	return (0);
}

char		*get_right(char *line, int mode, int mult)
{
	int		mask;
	int		dec;

	dec = 0;
	mask = 4 * mult;
	while (dec < 3)
	{
		if (mask >> dec & mode)
		{
			if (dec == 0)
				line[dec] = 'r';
			else if (dec == 1)
				line[dec] = 'w';
			else if (dec == 2)
				line[dec] = 'x';
		}
		else
			line[dec] = '-';
		dec++;
	}
	return (line);
}

char		*add_linked_path(t_all *node, char *line)
{
	char		buf[256];
	int			n;
	char		*path;

	path = NULL;
	if (!S_ISLNK(node->info->mode))
		return (line);
	if (!(line = ft_strjoindfree(line, ft_strdup(" -> "))))
		return (NULL);
	if ((n = readlink(node->name->path, buf, 255)) == -1)
		return (NULL);
	buf[n] = 0;
	if (!(path = ft_strdup((const char *)buf)))
	{
		free(line);
		return (NULL);
	}
	return (ft_strjoindfree(line, path));
}
