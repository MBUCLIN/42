/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:57:58 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/03 16:24:08 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int		is_dori(int sig)
{
	if (sig == 3 || sig == 15 || sig == 16 || sig == 18)
		return (-1);
	else if (sig == 13 || sig == 20 ||\
			sig == 21 || sig == 22 ||\
			sig == 	23 || sig == 29)
		return (1);
	return (0);
}

int		is_other(int sig)
{
	if (sig == 2 || sig == 28)
		return (1);
	return (0);
}

int		is_message(int sig)
{
	if (sig == 1 || sig == 14 ||\
		sig == 17 || sig == 19 ||\
		sig == 24 || sig == 25 ||\
		sig == 26 || sig == 27 ||\
		sig == 30 || sig == 31)
		return (1);
	else if (sig >= 4 && sig <= 12)
		return (1);
	return (0);
}
