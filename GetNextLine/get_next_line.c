#include "get_next_line.h"


t_readed	*get_fd(t_readed last, int const fd)
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

int		search_last_read(char *lrd, char *line)
{
	int		i;
	char	*tmp

	i = -1;
	while (lrd[++i])
	{
		if (lrd[i] == '\n')
		{
			if (!(line = ft_strsub(lrd, 0, i)))
				return (-1);
			if (!(tmp = ft_strsub(lrd, i, ft_strlen(lrd))))
				return (-1);
			free(lrd);
			lrd = NULL;
			lrd = tmp;
			return (1);
		}
	}
	return (0);
}

int		read_fd(char *lrd, char *line)
{
	char	buf[BUF_SIZE + 1];
	int		ret;
	char	*tmp;
	int		gob;

	while (ret = read(fd, buf, BUF_SIZE))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = ft_strjoinfree(lrd, buf);
		lrd = tmp;
		gob = search_last_read(lrd, line);
		if (gob == 1 || gob == -1)
			return (gob);
	}
	if (ft_strcpy(line, lrd) == NULL)
		return (-1);
	free (lrd);
	lrd = NULL;
	return (0);
}

void	del_nod(t_readed last, int const fd)
{
	t_readed	*tmp;
	int			i;
	t_readed	*tmp2;

	tmp2 = last;
	i = 0;
	tmp = get_fd(last, fd);
	if (tmp->lrd)
	{
		free(tmp->lrd);
		tmp->lrd = NULL;
	}

}

int		get_next_line(int const fd, char **line)
{
	t_readed	*tmp;
	int			gob;

	if (!(tmp = get_fd(last, fd)))
		return (-1);
	if (tmp->lrd)
		if ((gob = search_last_read(tmp->lrd, line)) != 0)
			return (gob);
	gob = read_fd(tmp->lrd, line);
	if (gob == 0)
		del_nod(last, fd);
		return (gob);
}
