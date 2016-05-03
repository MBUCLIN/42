/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 15:55:44 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/03 17:16:48 by mbuclin          ###   ########.fr       */
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
	if (mode & 010000)
		return ('p');
	else if (mode & 020000)
		return ('c');
	else if (mode & 040000)
		return ('d');
	else if (mode & 060000)
		return ('b');
	else if (mode & 0100000)
		return ('-');
	else if (mode & 0120000)
		return ('l');
	else if (mode & 0140000)
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
