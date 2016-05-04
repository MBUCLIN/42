/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:23:55 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/04 17:16:06 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		main(int ac, char **av)
{
	int			opt;
	t_all		*arg;
	t_all		*tmp;
	char		*line;
	t_maxl		*lenmax;

	opt = init_option(ac - 1, av + 1);
	ft_printf("%X : option\n", opt);
	if (opt == -1)
		return (0);
	if (!(arg = recup_args(ac - 1, av + 1)))
		return (0);
	if (!(arg = recup_info(arg, opt)))
		return (0);
	tmp = arg;
	lenmax = get_len_max(arg);
	arg = sort_list(arg, opt);
	while (tmp)
	{
		if (!(line = get_line_print(tmp, lenmax)))
		{
			del_all(arg);
			return (0);
		}
		ft_putendl(line);
		free(line);
		line = NULL;
		tmp = tmp->next;
	}
	del_all(arg);
	return (1);
}
