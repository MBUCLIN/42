/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_six_month.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 13:20:27 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/03 16:02:38 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	long			t;
	long			tf;
	struct stat		buf;

	t = time(&t);
	ft_printf("%D : t\n", t);
	if (stat(av[1], &buf))
		return (0);
	tf = buf.st_mtimespec.tv_sec;
	ft_printf("%D : tf\n", tf);
	if (tf > t)
		ft_putendl("date print futur");
	else if (tf < t - SX_M)
		ft_putendl("6 month earlier");
	else
		ft_putendl("full time print");
	return (1);
}
