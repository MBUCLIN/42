/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:57:11 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/20 13:35:37 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		print_y(int *y, size_t size)
{
	size_t		i;

	i = 0;
	if (y)
		while (i < size)
		{
			ft_printf("%3d", y[i]);
			i++;
		}
}
void		print_value_map(t_list *head)
{
	t_list		*tmp;

	tmp = head;
	while (tmp)
	{
		print_y((int *)tmp->content, (tmp->content_size / sizeof(int)));
		tmp = tmp->next;
		ft_putendl("");
	}
}
