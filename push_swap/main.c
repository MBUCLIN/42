/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:10:42 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/21 11:34:22 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int			put_msgel(unsigned int fd, const char *msg)
{
	ft_putendl_fd(fd, msg);
	return (0);
}

int					main(int argc, char **argv)
{
	char		*option;
	t_turn		*head;

	option = NULL;
	if (argc < 2)
		return (put_msgel(2, "error"));
	if (parse_arg((argv + 1)) != 1)
		return (put_msgel(2, "error"));
	if (!(option = init_option(argv + 1)))
		return (put_msgel(2, "error"));
	if (!(head = init_turn(argv + 1)))
		return (put_msgel(2, "error"));
	if (!(head = init_sort(head, option)))
		return (put_msgel(2, "error"));
	free(option);
	del_turn(head);
	return (1);
}
