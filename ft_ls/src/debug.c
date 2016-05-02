/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:26:51 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/27 18:30:57 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		print_name(t_all *head)
{
	t_all		*tmp;

	tmp = head;
	while (tmp)
	{
		ft_printf("%s : name\n", tmp->name->name);
		ft_printf("%s : path\n", tmp->name->path);
		ft_putendl("next\n");
		tmp = tmp->next;
	}
}
