/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:40:35 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/25 14:26:52 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		check_equals(ssize_t *num, int n)
{
	int		i;
	int		j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			if (j != i && num[i] == num[j])
				return (0);
	}
	return (1);
}

static int		parse_numbers(char **avplus, int n)
{
	int			i;
	ssize_t		*num;
	int			j;

	i = after_option(avplus) - 1;
	n -= i;
	if (!(num = (ssize_t *)malloc(sizeof(ssize_t) * (n + 1))))
		return (0);
	num[n] = 0;
	j = 0;
	while (avplus[++i])
	{
		num[j] = ft_satoi(avplus[i]);
		if ((num[j] < -2147483648 || num[j] > 2147483647))
		{
			return (ft_del_tab(num, 0));
		}
		j++;
	}
	if (check_equals(num, n) == 0)
		return (ft_del_tab(num, 0));
	return (ft_del_tab(num, 1));
}

static int		check_args(char *c)
{
	if (c[0] == '-' &&\
		!ft_isoption(c[1]) && !ft_isdigit(c[1]))
		return (0);
	else if (c[0] != '-' && !ft_isoption(c[0]) && !ft_isdigit(c[0]))
		return (0);
	return (1);
}

int				parse_arg(char **av)
{
	int		i;
	int		j;
	int		n;
	int		o;

	i = -1;
	n = 0;
	while (av[++i])
	{
		j = -1;
		o = 0;
		while (av[i][++j])
			if (av[i][j] <= '9' && av[i][j] >= '0')
				n = 1;
			else if (ft_isoption(av[i][j]))
				o = 1;
			else if (!check_args(&av[i][j]))
				return (0);
		if (n && o)
			return (0);
	}
	return (parse_numbers(av, i - 1));
}
