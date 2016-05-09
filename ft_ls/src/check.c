/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:58:40 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/09 15:30:11 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			check_times_option(int option)
{
	int		time;
	int		mask;

	time = 0;
	mask = OPT_MU;
	if (mask & option)
		time = 0b10;
	mask >>= 1;
	if (mask & option)
		time = 0b1;
	return (time);
}

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
		if (!ft_isoption(arg[i], "lRratuU"))
			return (-1);
		if (arg[i] == 'l' && !(opt & OPT_L))
			opt += OPT_L;
		else if (arg[i] == 'R' && !(opt & OPT_MR))
			opt += OPT_MR;
		else if (arg[i] == 'r' && !(opt & OPT_R))
			opt += OPT_R;
		else if (arg[i] == 'a' && !(opt & OPT_A))
			opt += OPT_A;
		else if (arg[i] == 't' && !(opt & OPT_T))
			opt += OPT_T;
		else if (arg[i] == 'u' && !(opt & OPT_U))
			opt += OPT_U;
		else if (arg[i] == 'U' && !(opt & OPT_MU))
			opt += OPT_MU;
		i++;
	}
	return (opt);
}
