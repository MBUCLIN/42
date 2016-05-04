/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:42:34 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/04 16:47:52 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	if (ac < 3)
		return (0);
	if (!ft_islexisort(av[1], av[2]))
		ft_printf("%s, [s1] est lexicographicalement avant [s2] %s\n", av[1], av[2]);
	else
		ft_printf("%s, [s2] est lexicographicalement avant [s1] %s\n", av[2], av[1]);
	return (1);
}
