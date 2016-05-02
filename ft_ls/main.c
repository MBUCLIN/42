/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:23:55 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/27 18:52:12 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		main(int ac, char **av)
{
	int			opt;
	t_all		*arg;

	opt = init_option(ac - 1, av + 1);
	if (opt == -1)
		return (0);
	if (!(arg = recup_args(ac - 1, av + 1)))
		return (0);
	print_name(arg);
	del_all(arg);
	return (1);
}
