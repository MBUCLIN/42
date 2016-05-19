/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 15:15:19 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/19 17:46:59 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		main(int ac, char **av)
{
	t_list		*map;

	map = NULL;
	if (ac != 2)
	{
		ft_putendl_fd(2, "fdf: Wrong number of arguments");
		return (0);
	}
	if ((map = open_map(av[1])) == NULL)
		return (0);
	print_value_map(map);
	ft_lstdel(&map, &del_map);
	return (1);
}
