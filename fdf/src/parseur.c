/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 15:22:08 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/18 16:57:45 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			check_line(int *y, int n)
{
	int		x;

	x = 0;
	while (y[x])
	{
		x++;
	}
	if (x != n)
		return (0);
	return (1);
}

int			parse_map(t_lst *lines)
{
	t_lst		*tmp;
	int			nn;

	nn = 0;
	tmp = lines;
	while (tmp)
	{
		if (!(nn = check_line(tmp->content, nn)))
		{
			ft_lstdel(lines, &del_content);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
