/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:40:29 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/21 11:32:58 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			if (ft_isoption(arg[i][j], "cns"))
				opt = 1;
		}
		if (opt == 0)
			return (i);
	}
	return (0);
}
