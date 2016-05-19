/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabasep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:23:49 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/10 10:23:50 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	check_base(const char *base)
{
	size_t		i;
	size_t		j;
	int			match;

	i = -1;
	if (base == NULL || ft_strlenp(base) == 0)
		return (0);
	match = 0;
	while (base[++i])
	{
		j = -1;
		while (base[++j])
			if (base[j] == base[i])
				match++;
		if (match != 1)
			return (0);
		match = 0;
	}
	return (1);
}

static int	get_size(unsigned int nbr, const char *base)
{
	size_t		size;
	size_t		len;

	size = ft_strlenp(base);
	len = 0;
	while (nbr)
	{
		nbr = nbr / size;
		len++;
	}
	return (len);
}

char		*ft_itoabasep(unsigned int nbr, const char *base)
{
	char		*convert;
	size_t		sbase;
	int			i;

	if (!(check_base(base)))
		return (NULL);
	else if (nbr == 0)
		return (ft_strdupp("0"));
	sbase = ft_strlenp(base);
	i = get_size(nbr, base);
	if (!(convert = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (--i >= 0)
	{
		convert[i] = base[nbr % sbase];
		nbr = nbr / sbase;
	}
	return (convert);
}
