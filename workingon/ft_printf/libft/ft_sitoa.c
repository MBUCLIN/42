/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:19:10 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/24 17:03:19 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	get_sizenbr(ssize_t nbr)
{
	int		size;

	size = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		size++;
	}
	while (nbr)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

char		*ft_sitoa(ssize_t nbr)
{
	int		size;
	char	*ret;

	if (nbr * -1 - 1 == 9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	else if (nbr == 0)
		return (ft_strdup("0"));
	size = get_sizenbr(nbr);
	if (!(ret = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		ret[0] = '-';
	}
	size -= 1;
	while (ret[size] != '-' && size >= 0)
	{
		ret[size] = nbr % 10 + 48;
		nbr = nbr / 10;
		size--;
	}
	return (ret);
}
