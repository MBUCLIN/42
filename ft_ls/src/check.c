/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:58:40 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/27 18:02:30 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			check_option(char *arg)
{
	int		i;
	int		opt;

	i = 1;
	opt = 0;
	if (arg[0] != '-')
		return (0);
	else if (arg[1] == '-' && !arg[2])
		return (0);
	while (arg[i])
	{
		if (!ft_isoption(arg[i], "lRrat"))
			return (-1);
		if (arg[i] == 'l' && !(opt & 1))
			opt += 0b1;
		else if (arg[i] == 'R' && !(opt & 2))
			opt += 0b10;
		else if (arg[i] == 'r' && !(opt & 4))
			opt += 0b100;
		else if (arg[i] == 'a' && !(opt & 8))
			opt += 0b1000;
		else if (arg[i] == 't' && !(opt & 16))
			opt += 0b10000;
		i++;
	}
	return (opt);
}
