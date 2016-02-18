/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getadj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:54:56 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/18 16:54:59 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_getadj(char *info)
{
	int		i;
	int		adj;

	i = 0;
	adj = 0;
	while (info[i])
	{
		if (info[i] == '-')
			return ('r');
		else if (info[i] == '0')
			adj = 'l';
		i++;
	}
	return (adj);
}
