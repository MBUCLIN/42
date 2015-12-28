/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstedit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:15:41 by lgosse            #+#    #+#             */
/*   Updated: 2015/12/28 14:16:17 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_proto.h"

int		ft_lstlen(t_sample *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_change_lst_char(t_sample *lst)
{
	int y;
	int x;

	y = -1;
	while (lst)
	{
		while (lst->tetri[++y])
		{
			x = -1;
			while (lst->tetri[y][++x] != '\0')
			{
				if (lst->tetri[y][x] == '#')
					lst->tetri[y][x] = lst->c;
			}
		}
		lst = lst->next;
	}
}

void	ft_lstdestroy(t_sample *lst)
{
	t_sample *tmp;

	tmp = NULL;
	while (lst)
	{
		ft_tabdel((void **)lst->tetri);
		lst->tetri = NULL;
		tmp = lst->next;
		lst->next = NULL;
		free(lst);
		lst = NULL;
		lst = tmp;
	}
}
