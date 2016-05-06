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
		if (tmp->info->mode & 010000)
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
