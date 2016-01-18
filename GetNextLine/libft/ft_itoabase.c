/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 15:17:01 by mbuclin           #+#    #+#             */
/*   Updated: 2015/12/13 15:17:04 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(char *base)
{
	size_t		i;
	size_t		j;
	int			match;

	i = -1;
	if (base == NULL || ft_strlen(base) == 0)
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

static int	get_size(unsigned int nbr, char *base)
{
	size_t		size;
	size_t		len;

	size = ft_strlen(base);
	len = 0;
	while (nbr / size)
	{
		len++;
		nbr = nbr / size;
	}
	return (len + 1);
}

char		*ft_itoabase(unsigned int nbr, char *base)
{
	char		*convert;
	size_t		sbase;
	size_t		i;

	i = get_size(nbr, base);
	if (!(check_base(base)))
		return (NULL);
	if (!(convert = (char *)ft_memalloc(sizeof(char) * i)))
		return (NULL);
	i--;
	sbase = ft_strlen(base);
	while (nbr)
	{
		convert[i] = base[nbr % sbase];
		nbr = nbr / sbase;
		i--;
	}
	return (convert);
}