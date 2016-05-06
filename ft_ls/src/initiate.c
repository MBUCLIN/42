/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:55:33 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/04 17:11:36 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_all		*recup_args(int ac, char **av, int option)
{
	t_all		*head;
	t_all		*tmp;
	int			i;

	i = after_option(av, "lRratuU");
	if (i == ac)
		return (new_node_all(new_name("./", "./"), option));
	if (!(head = new_node_all(new_name(av[i], av[i]), option)))
		return (NULL);
	while (av[++i])
	{
		if (!(tmp = new_node_all(new_name(av[i], av[i]), option)))
			return (del_all(head));
		if (!(head = import(head, tmp, option)))
			return (NULL);
	}
	return (head);
}

int			init_option(int ac, char **av)
{
	int		i;
	int		tmp;
	int		opt;

	i = 0;
	opt = 0;
	if (ac == 1)
		return (0);
	while (av[i])
	{
		if (!(tmp = check_option(av[i])))
			return (opt);
		else if (tmp == -1)
			return (error_option(av[i]));
		opt += tmp;
		i++;
	}
	return (opt);
}
