/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:40:29 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 17:43:59 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				ft_isoption(int c)
{
	if (c == 'n' || c == 's' || c == 'c')
		return (1);
	return (0);
}

int				after_option(char **arg)
{
	int		i;
	int		j;
	int		opt;

	i = -1;
	while (arg[++i])
	{
		j = -1;
		opt = 0;
		while (arg[i][++j])
		{
			if (ft_isoption(arg[i][j]))
				opt = 1;
		}
		if (opt == 0)
			return (i);
	}
	return (0);
}
