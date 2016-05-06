/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:45:15 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/03 13:42:12 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		total_size(t_all *head, int option)
{
	int		total;
	t_all		*tmp;

	tmp = head;
	total = 0;
	while (tmp)
	{
		ft_putendl(tmp->name->name);
		if (tmp->name->name[0] != '.' || (option & OPT_A))
		{
			ft_printf("tmp name : %s\n", tmp->name->name);
			total += tmp->info->size;
		}
		tmp = tmp->next;
	}
	return (total / 512);
}

t_all		*print_file(t_all *head, int option)
{
	t_all		*tmp;
	char		*line;
	t_maxl		*max;

	if (!(max = get_len_max(head)))
		return(del_all(head));
	tmp = head;
	while (tmp)
	{
		if (tmp->info->mode & 0100000)
		{
			if (!(line = choose_line(tmp, max, option)))
				return (del_all(head));
			ft_putendl(line);
			free(line);
			line = NULL;
		}
		tmp = tmp->next;
	}
	return (head);
}

t_all		*print_dir(t_all *head, t_maxl *max, int option)
{
	t_all	*tmp;
	char	*line;

	tmp = head;
	while (tmp)
	{
		if (tmp->name->name[0] != '.' || (option & OPT_A))
		{
			if (!(line = choose_line(tmp, max, option)))
				return (del_all(head));
			ft_putendl(line);
			free(line);
			line = NULL;
		}
		tmp = tmp->next;
	}
	return (head);
}
