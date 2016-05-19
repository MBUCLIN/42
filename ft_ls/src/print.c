/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:45:15 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/19 13:49:13 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					total_size(t_all *head, int option)
{
	int			total;
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

static int			can_print_file(t_all *node, t_maxl *max, int option)
{
	char		*line;

	if (!(line = choose_line(node, max, option)))
		return (0);
	ft_putendl(line);
	free(line);
	line = NULL;
	return (1);
}

static int			all_len(t_all *head)
{
	int		i;
	t_all	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_all				*print_file(t_all *head, int option)
{
	t_all		*tmp;
	t_maxl		*max;
	int			n;
	int			t;

	if (!(max = get_len_max(head)))
		return (del_all(head));
	tmp = head;
	n = 0;
	t = 0;
	while (tmp)
	{
		if (check_file(tmp, option))
			if (!(n = can_print_file(tmp, max, option)))
				return (del_all(head));
		t += n;
		tmp = tmp->next;
	}
	if (n == 1 && !(t == all_len(head)))
		ft_putendl("");
	free(max);
	return (head);
}

t_all				*print_dir(t_all *head, t_maxl *max, int option)
{
	t_all	*tmp;
	char	*line;

	tmp = head;
	if (test_list(head, option) && (option & OPT_L))
		ft_printf("total %d\n", total_size(head, option));
	while (tmp)
	{
		if (tmp->info->mode == 0)
			put_error(tmp->name->name);
		else if (tmp->name->name[0] != '.' || (option & OPT_A) == OPT_A)
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
