/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:55:53 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/24 16:48:58 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check_number(char **split, int size)
{
	long		n;
	int			i;

	i = 0;
	while (split[i])
	{
		n = ft_satoi(split[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_deltabstr(split, size);
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != '-')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int		check_map(t_list *head)
{
	t_list		*tmp;
	size_t		cs;

	tmp = head;
	cs = tmp->content_size;
	while (tmp)
	{
		if (tmp->content_size != cs)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		check_coordonne(t_cdn *cdn, int h)
{
	if (cdn->x1 <= 0 || cdn->y1 <= 0 || cdn->y2 <= 0 || cdn->x2 <= 0)
	{
		return (0);
	}
	if (cdn->x2 >= h || cdn->y2 >= h || cdn->y1 >= h || cdn->x1 >= h)
	{
		return (0);
	}
	return (1);
}

int		check_tile(int tile, t_img *img)
{
	if ((img->h / 2) + (tile / 2) - img->z < 0)
		return (0);
	ft_printf("%d : calc", (img->h / 2) + ((img->x / 2) + (img->y)) + (tile / 2) - -img->z);
	if ((img->h / 2) + ((img->x / 2) + img->y) + (tile / 2) - -img->z > img->h)
		return (0);
	return (1);
}
