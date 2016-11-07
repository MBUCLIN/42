/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:16:35 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/14 16:30:27 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_get_nbits(int wint)
{
	unsigned int	mask;
	int				n;

	n = 32;
	mask = 0x80000000;
	while ((mask & wint) == 0)
	{
		n--;
		mask = mask >> 1;
	}
	return (n);
}
