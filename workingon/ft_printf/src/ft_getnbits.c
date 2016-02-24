/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:20:40 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/24 15:20:42 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_get_nbits(int wint)
{
	int				n;
	unsigned int	mask;

	n = 32;
	mask = 0x80000000;
	while (n)
	{
		if (mask & wint)
			return (n);
		mask >>= 1;
		n--;
	}
	return (0);
}
