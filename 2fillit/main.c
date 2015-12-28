/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:05:09 by lgosse            #+#    #+#             */
/*   Updated: 2015/12/17 17:24:29 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_proto.h"

int		main(int ac, char **av)
{
	char		**sample;
	char		**map;
	t_sample	*lst;

	sample = ft_read_sample(av[1]);
	if (sample == NULL)
		return (0);
	lst = ft_treat_sample(sample);
	ft_tabdel((void **)sample);
	if (lst != NULL)
		map = ft_init_solv(lst);
	ft_lstdestroy(lst);
	if (map != NULL)
		ft_puttab(map);
	ft_tabdel((void **)map);
	return (0);
}
