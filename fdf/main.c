/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 15:15:19 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/21 19:08:14 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		main(int ac, char **av)
{
	t_list		*map;
	t_all		*ev;

	map = NULL;
	if (ac != 2)
	{
		ft_putendl_fd(2, "fdf: Wrong number of arguments");
		return (0);
	}
	if ((map = open_map(av[1])) == NULL)
		return (0);
	print_value_map(map);
	if ((ev = (t_all *)malloc(sizeof(t_all))) == NULL)
	{
		ft_putendl_fd(2, "fdf: malloc error");
		ft_lstdel(&map, &del_map);
		return (0);
	}
	ev->map = map;
	if ((ev = initiate_mlx(ev)) == NULL)
		return (0);
	if (draw_image(&ev) == 0)
		return (0);
	mlx_key_hook(ev->win->win, &key_event, ev);
//	mlx_mouse_hook(ev->win->win, &mouse_event, ev);
	mlx_loop(ev->win->mlx);
	return (1);
}
