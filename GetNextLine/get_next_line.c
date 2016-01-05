/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:41:10 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/04 18:01:54 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_readed	*get_fd(t_readed **last, int const fd)
{
	t_readed	*tmp;

	tmp = *last;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_readed *)ft_memalloc(sizeof(t_readed))))
		return (NULL);
	tmp->fd = fd;
	tmp->lrd = NULL;
	tmp->next = *last;
	*last = tmp;
	return (tmp);
}

int		search_last_read(t_readed *lrd, char **line)
{
	int		i;
	char	*tmp;

	i = -1;
	while (lrd->lrd[++i])
	{
		if (lrd->lrd[i] == '\n')
		{
			if (!(*line = ft_strsub(lrd->lrd, 0, i)))
				return (-1);
			if (!(tmp = ft_strdup(lrd->lrd)))
				return (-1);
			free(lrd->lrd);
			lrd->lrd = NULL;
			if (!(lrd->lrd = ft_strsub(tmp, i + 1, ft_strlen(tmp) - i)))
				return (-1);
			free(tmp);
			tmp = NULL;
			return (1);
		}
	}
	return (0);
}

int		read_fd(int const fd, t_readed *lrd, char **line)
{
	char	buf[BUF_SIZE + 1];
	int		ret;
	int		size;
	int		gob;

	ret = 1;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		size = ft_strlen(lrd->lrd);
		lrd->lrd = ft_strjoinfree(lrd->lrd, buf);
		gob = search_last_read(lrd, line);
		if (line)
			if (gob == 1 || gob == -1)
				return (gob);
	}
    if (lrd->lrd == NULL)
        return (0);
    if ((*line = ft_strdup(lrd->lrd)) == NULL)
		return (-1);
	free (lrd->lrd);
	lrd->lrd = NULL;
	return (1);
}

void	del_nod(t_readed *last, int const fd)
{
	t_readed	*tmp;
	int			i;
	t_readed	*tmp2;

	i = 0;
	tmp = get_fd(&last, fd);
	if (tmp->lrd)
	{
		free(tmp->lrd);
		tmp->lrd = NULL;
	}
	if (tmp->next == NULL)
	{
		free(tmp);
		tmp = NULL;
		return ;
	}
	tmp2 = last;
	while (tmp2->next->fd != fd && tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp->next;
	free(tmp);
	tmp = NULL;
}

int		get_next_line(int const fd, char **line)
{
	static t_readed		*last = NULL;
	t_readed			*tmp;
	int					gob;

	if (!(tmp = get_fd(&last, fd)))
		return (-1);
	if (tmp->lrd)
		if ((gob = search_last_read(tmp, line)) != 0)
		{
			return (gob);
		}
	gob = read_fd(fd, tmp, line);
	if (gob == 0)
		del_nod(last, fd);
	return (gob);
}
