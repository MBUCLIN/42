/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:39:56 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/13 12:16:08 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_puterror(char *msg)
{
	ft_putendl(msg);
	return (0);
}

int		error_option(char *arg_er)
{
	int		c;

	c = ft_chrnotoption(arg_er + 1, "lRratuU");
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_putendl("usage: ft_ls [-lRratuU]");
	return (-1);
}

int		test_dir(t_all *node)
{
	DIR		*dir;

	dir = NULL;
	if (S_ISDIR(node->info->mode))
	{
		if (!(dir = opendir(node->name->path)))
			return (0);
		closedir(dir);
	}
	else if (node->info->mode == 0)
		return (0);
	return (1);
}

int		test_list(t_all *head, int option)
{
	t_all	*tmp;
	int		i;

	tmp = head;
	i = 0;
	while (tmp)
	{
		if (tmp->name->name[0] == '.' && (option & OPT_A))
			i++;
		else if (tmp->name->name[0] != '.')
			i++;
		tmp = tmp->next;
	}
	return (i);
}
