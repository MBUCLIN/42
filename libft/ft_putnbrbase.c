/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:38:49 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/13 15:44:39 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_base(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (base == NULL)
		return (0);
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[j] == base[i] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void			ft_putnbrbase(int nbr, char *base)
{
	if (!(check_base(base)))
		return ;
	if (nbr * -1 - 1 == 2147483647)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nbr < 0 && ft_strlen(base) == 10)
	{
		nbr = nbr * -1;
		ft_putchar('-');
	}
	else if (nbr < 0 && ft_strlen(base) != 10)
		return ;
	if (nbr / ft_strlen(base) != 0)
		ft_putnbrbase(nbr / ft_strlen(base), base);
	ft_putchar(base[nbr % ft_strlen(base)]);
}
