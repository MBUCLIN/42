/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:41:10 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/02 18:53:50 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_readed	*get_fd(t_readed *last, int const fd)
{
	t_readed	*tmp;

	tmp = last;
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
	return (tmp);
}

int		search_last_read(char *lrd, char **line)
{
	int		i;
	char	*tmp;

	i = -1;
	while (lrd[++i])
	{
		if (lrd[i] == '\n')
		{
			ft_putnbr(i);
			if (!(*line = ft_strsub(lrd, 0, i)))
				return (-1);
			if (!(tmp = ft_strsub(lrd, i + 1, ft_strlen(lrd) - i)))
				return (-1);
			free(lrd);
			lrd = NULL;
			lrd = tmp;
			return (1);
		}
	}
	return (0);
}

int		read_fd(int const fd, char *lrd, char **line)
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
		size = ft_strlen(lrd);
		lrd = ft_strjoinfree(lrd, buf);
		gob = search_last_read(lrd, line);
		if (line)
		if (gob == 1 || gob == -1)
			return (gob);
	}
	if (ft_strcpy(*line, lrd) == NULL)
		return (-1);
	free (lrd);
	lrd = NULL;
	return (0);
}

void	del_nod(t_readed *last, int const fd)
{
	t_readed	*tmp;
	int			i;
	t_readed	*tmp2;

	i = 0;
	tmp = get_fd(last, fd);
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
	static t_readed		*last;
	t_readed			*tmp;
	int					gob;

	if (!(tmp = get_fd(last, fd)))
		return (-1);
	if (tmp->lrd)
		if ((gob = search_last_read(tmp->lrd, line)) != 0)
			return (gob);
	gob = read_fd(fd, tmp->lrd, line);
	if (gob == 0)
		del_nod(last, fd);
		return (gob);
}
