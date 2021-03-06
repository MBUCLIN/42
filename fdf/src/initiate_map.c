/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 14:31:06 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/30 12:10:16 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			convert_split(char **split, t_list **new)
{
	int		*content;
	int		cs;

	cs = ft_tabstrlen(split);
	if ((content = (int *)malloc(sizeof(int) * (cs + 1))) == NULL)
	{
		ft_putendl_fd(2, "fdf: malloc error");
		ft_deltabstr(split, cs);
		return (0);
	}
	cs = -1;
	while (split[++cs])
		content[cs] = ft_atoi(split[cs]);
	content[cs] = 0;
	ft_deltabstr(split, cs);
	if ((*new = ft_lstnew(content, cs * sizeof(int))) == NULL)
	{
		ft_putendl_fd(2, "fdf: malloc error");
		return (0);
	}
	(*new)->next = NULL;
	free(content);
	return (1);
}

int			stock_map(char *line, t_list **map)
{
	char		**split;
	t_list		*new;

	if ((split = ft_strsplit(line, ' ')) == NULL)
	{
		ft_putendl_fd(2, "fdf: malloc error");
		ft_lstdel(map, &del_map);
		return (0);
	}
	if (!check_number(split, ft_tabstrlen(split)) || !check_line(line))
	{
		ft_putendl_fd(2, "fdf: map error");
		ft_lstdel(map, &del_map);
		return (0);
	}
	if (!(convert_split(split, &new)))
	{
		ft_lstdel(map, &del_map);
		return (0);
	}
	if (*map)
		ft_lstaddend(map, new);
	else
		*map = new;
	return (1);
}

t_list		*read_file_map(int fd)
{
	int		ret;
	char	*line;
	t_list	*map;

	map = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(stock_map(line, &map)))
		{
			free(line);
			return (NULL);
		}
		free(line);
		line = NULL;
	}
	if (ret == -1 || map == NULL)
	{
		ft_putendl_fd(2, "fdf: get_next_line could not read the file");
		ft_lstdel(&map, &del_map);
		return (NULL);
	}
	return (map);
}

t_list		*open_map(char *filename)
{
	int		fd;
	t_list	*map;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putendl_fd(2, "fdf: Could not open the file");
		return (NULL);
	}
	if ((map = read_file_map(fd)) == NULL)
	{
		close(fd);
		return (NULL);
	}
	if (!check_map(map))
	{
		ft_putendl_fd(2, "fdf: map error");
		return (NULL);
	}
	if (close(fd) == -1)
	{
		ft_putendl_fd(2, "fdf: Error while closing file");
		ft_lstdel(&map, &del_map);
		return (NULL);
	}
	return (map);
}
