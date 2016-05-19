/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:29:24 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/19 13:49:01 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		main(int argc, char **argv)
{
	int		opt;
	t_all	*arg;

	opt = init_option(argc - 1, argv + 1);
	if (opt == -1)
		return (0);
	if (!(arg = recup_args(argc - 1, argv + 1, opt)))
		return (0);
	print_file(arg, opt);
	arg = del_only_file(arg, opt);
	if (arg && (opt & OPT_MR))
	{
		arg->printname = 1;
		if (!(arg = recursive(arg, opt, 0)))
			return (0);
	}
	else if (arg)
		arg = read_dir_arg(arg, opt);
	del_all(arg);
	return (1);
}
