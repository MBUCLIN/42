/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:39:56 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/02 16:25:40 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_puterror(char *msg)
{
	ft_putendl(msg);
	return (0);
}

int		error_option(char *arg_er)
{
	int		c;

	c = ft_chrnotoption(arg_er + 1, "lRratuU");
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_putendl("usage: ft_ls [-lRratuU]");
	return (-1);
}
