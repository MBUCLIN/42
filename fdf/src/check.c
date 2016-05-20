/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:55:53 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/20 14:17:25 by mbuclin          ###   ########.fr       */
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
