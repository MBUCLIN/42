/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:41:10 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/08 16:55:57 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

t_readed			*get_fd(t_readed **last, int const fd)
{
	t_readed	*tmp;

	tmp = *last;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_readed *)malloc(sizeof(t_readed))))
		return (NULL);
	tmp->fd = fd;
	tmp->lrd = NULL;
	tmp->next = *last;
	*last = tmp;
	return (tmp);
}

int					search_last_read(t_readed *lrd, char **line)
{
	int		i;
	char	*tmp;

	i = -1;
	while (lrd->lrd[++i])
		if (lrd->lrd[i] == '\n')
		{
			if (i == 0)
			{
				if (!(*line = ft_strsub(lrd->lrd, 0, 0)))
					return (-1);
			}
			else if (!(*line = ft_strsub(lrd->lrd, 0, i)))
				return (-1);
			if (!(tmp = ft_strdup(lrd->lrd)))
				return (-1);
			free(lrd->lrd);
			lrd->lrd = NULL;
			if (!(lrd->lrd = ft_strsub(tmp, i + 1, ft_strlen(tmp + i + 1))))
				return (-1);
			free(tmp);
			tmp = NULL;
			return (1);
		}
	return (0);
}

int					read_fd(int const fd, t_readed *lrd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		gob;
	int		i;

	ret = 1;
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		lrd->lrd = ft_strjoinfree(lrd->lrd, buf);
		gob = search_last_read(lrd, line);
		if (line)
			if (gob == 1 || gob == -1)
				return (gob);
		i++;
	}
	if ((i == 0 && lrd->lrd == NULL) || (lrd->lrd[0] == '\0' && i == 0))
		return (0);
	if ((*line = ft_strdup(lrd->lrd)) == NULL)
		return (-1);
	return (2);
}

void				del_nod(t_readed *todel, t_readed **last)
{
	if (todel->next)
		*last = todel->next;
	if (todel->lrd)
	{
		free(todel->lrd);
		todel->lrd = NULL;
	}
	if (todel->next)
	{
		todel->next = NULL;
		free(todel);
		todel = NULL;
		return ;
	}
}

int					get_next_line(int const fd, char **line)
{
	static t_readed		*last = NULL;
	t_readed			*tmp;
	int					gob;

	if (fd == -1)
		return (fd);
	if (!(tmp = get_fd(&last, fd)))
		return (-1);
	if (tmp->lrd)
		if ((gob = search_last_read(tmp, line)) != 0)
			return (gob);
	gob = read_fd(fd, tmp, line);
	if (gob == 2 || gob == 0)
	{
		del_nod(tmp, &last);
		if (gob == 2)
			return (1);
	}
	return (gob);
}
