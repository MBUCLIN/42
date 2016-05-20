/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_keyevent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:30:45 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/20 16:34:40 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	end_fdf(t_all *ev)
{
	del_event(ev);
	exit(1);
}

int		key_event(int keycode, t_all *ev)
{
	if (keycode == 53 || keycode == 12)
		end_fdf(ev);
	else
		ft_printf("keycode : %d\n", keycode);
	return (0);
}
