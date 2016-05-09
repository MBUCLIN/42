/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:26:51 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/09 15:20:45 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		print_info(t_all *node)
{
	ft_printf("%s : gr_name\n", node->info->gr_name);
	ft_printf("%s : us_name\n", node->info->us_name);
	ft_printf("%o : mode\n", node->info->mode);
	ft_printf("%D : time\n", node->info->time);
	ft_printf("%d : size\n", node->info->size);
	ft_printf("%d : hardl\n", node->info->hardl);
}
void		print_name(t_all *node)
{
	ft_printf("%s : name\n", node->name->name);
	ft_printf("%s : path\n", node->name->path);
}

char		*print_mode(int mode)
{
	char		*linemode;

	if (!(linemode = get_line_mode(mode)))
		return (NULL);
	ft_putendl(linemode);
	free(linemode);
	return (NULL);
}

void		print_node(t_all *node)
{
	print_name(node);
//	print_info(node);
//	print_mode(node->info->mode);
}

void		print_all(t_all *head)
{
	t_all		*tmp;

	tmp = head;
	while (tmp)
	{
		print_node(tmp);
		if (tmp->next)
			ft_putendl("next\n");
		tmp = tmp->next;
	}
}
