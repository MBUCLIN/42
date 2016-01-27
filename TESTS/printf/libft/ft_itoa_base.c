/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:34:57 by lgosse            #+#    #+#             */
/*   Updated: 2015/11/27 16:31:09 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_nb_length(int n, int base)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(int n, int base)
{
	char	*nb;
	char	*tab;
	int		i;

	if (base == 10)
		return (ft_itoa(n));
	i = ft_get_nb_length(n, base);
	nb = ft_strnew(17);
	tab = ft_strdup("0123456789ABCDEF");
	while (--i >= 0)
	{
		nb[i] = tab[n % base];
		n /= base;
	}
	free(tab);
	return (nb);
}
