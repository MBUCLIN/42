/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sitoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:19:33 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/10 16:19:56 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		check_base(const char *base)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (i != j && base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int		get_size(size_t nbr, int base)
{
	int		size;

	size = 0;
	while (nbr)
	{
		nbr /= base;
		size++;
	}
	return (size);
}

char			*ft_sitoabase(size_t nbr, const char *base)
{
	int		size;
	char	*ret;
	int		div;

	if (!(check_base(base)))
		return (NULL);
	else if (nbr == 0)
		return (ft_strdup("0"));
	div = ft_strlen(base);
	size = get_size(nbr, div);
	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size] = 0;
	size -= 1;
	while (size >= 0)
	{
		ret[size] = base[nbr % div];
		nbr /= div;
		size--;
	}
	return (ret);
}
