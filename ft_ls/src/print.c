/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:45:15 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/10 12:22:40 by mbuclin          ###   ########.fr       */
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
		if (tmp->name->name[0] != '.' || (option & OPT_A))
			total += tmp->info->blck;
		tmp = tmp->next;
	}
	return (total);
}

t_all		*print_file(t_all *head, int option)
{
	t_all		*tmp;
	char		*line;
	t_maxl		*max;
	int			n;

	if (!(max = get_len_max(head)))
		return(del_all(head));
	tmp = head;
	n = 0;
	while (tmp)
	{
		if (!(check_dir(tmp, option)))
		{
			n = 1;
			if (!(line = choose_line(tmp, max, option)))
				return (del_all(head));
			ft_putendl(line);
			free(line);
			line = NULL;
		}
		tmp = tmp->next;
	}
	if (n)
		ft_putendl("");
	free(max);
	return (head);
}

t_all		*print_dir(t_all *head, t_maxl *max, int option)
{
	t_all	*tmp;
	char	*line;

	tmp = head;
	if (option & OPT_L)
		printf("total %d\n", total_size(head, option));
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
	free(max);
	return (head);
}
