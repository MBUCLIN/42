/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 15:55:44 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/10 12:35:14 by mbuclin          ###   ########.fr       */
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
	if (mode & S_IFIFO)
		return ('p');
	else if (mode & S_IFCHR)
		return ('c');
	else if (mode & S_IFDIR)
		return ('d');
	else if (mode & S_IFBLK)
		return ('b');
	else if (mode & S_IFREG)
		return ('-');
	else if (mode & S_IFLNK)
		return ('l');
	else if (mode & S_IFSOCK)
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
