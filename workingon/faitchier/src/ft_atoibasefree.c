/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibasefree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:56:57 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/14 15:01:33 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		check_base(char *base)
{
	int			i;
	int			j;

	i = -1;
	while (base[++i])
	{
		j = -1;
		while (base[++j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
		}
	}
	return (1);
}

static int		check_nbr(char *nbr_b, char *base)
{
	int			i;
	int			j;
	int			match;

	i = -1;
	match = 0;
	while (nbr_b[++i])
	{
		j = -1;
		while (base[++j])
		{
			if (nbr_b[i] == base[j] || nbr_b[i] == '-')
				match = 1;
		}
		if (match != 1)
			return (0);
		match = 0;
	}
	return (1);
}

static int		get_number(char *nbr_b, char *base)
{
	int			i;
	int			j;
	int			nbr;

	i = 0;
	nbr = 0;
	while (nbr_b[i])
	{
		if (nbr_b[i] == '-')
			i++;
		j = 0;
		while (base[j] && base[j] != nbr_b[i])
			j++;
		if (base[j] != '\0')
		{
			nbr = nbr * ft_strlen(base) + j;
		}
		i++;
	}
	return (nbr);
}

int				ft_atoibasefree(char *nbr_b, char *base)
{
	unsigned int		nbr;

	nbr = 0;
	if (nbr_b == NULL || base == NULL)
		return (0);
	if (check_nbr(nbr_b, base) == 0 || check_base(base) == 0)
		return (0);
	nbr = get_number(nbr_b, base);
	free(nbr_b);
	return (nbr);
}
