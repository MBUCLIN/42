/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:25:06 by lgosse            #+#    #+#             */
/*   Updated: 2015/12/11 15:00:30 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_nb_length(int n)
{
	int len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*nb;
	int		i;

	nb = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_get_nb_length(n);
	if ((nb = ft_strnew(i)))
	{
		if (n < 0)
		{
			n = -n;
			nb[0] = '-';
		}
		while (i >= 0 && nb[--i] != '-')
		{
			nb[i] = n % 10 + '0';
			n /= 10;
		}
	}
	return (nb);
}
