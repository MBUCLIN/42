/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:59:56 by mbuclin           #+#    #+#             */
/*   Updated: 2015/12/01 16:12:08 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nbr)
{
	if (nbr * -1 - 1 == 2147483647)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr / 10 != 0)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + 48);
}
