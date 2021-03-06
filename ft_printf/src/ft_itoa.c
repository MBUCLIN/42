/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:01:26 by mbuclin           #+#    #+#             */
/*   Updated: 2015/12/15 14:41:03 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		check_size(int nbr)
{
	int		size;

	size = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		size = 1;
		nbr = nbr * -1;
	}
	while (nbr)
	{
		size++;
		nbr = nbr / 10;
	}
	return (size);
}

char			*ft_itoa(int nbr)
{
	char	*str;
	int		size;

	if (nbr * -1 - 1 == 2147483647)
		return (ft_strdupp("-2147483648"));
	else if (nbr == 0)
		return (ft_strdupp("0"));
	size = check_size(nbr);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	while (--size >= 0 && str[size] != '-')
	{
		str[size] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (str);
}
