/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:20:10 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/24 15:20:11 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			get_ncar(int *wchar)
{
	int		i;

	i = 0;
	while (*(wchar + i) != 0x0)
		i++;
	return (i);
}

static char			*apply_wchar(int ncar, int *wchar)
{
	char	*oct;
	int		n;
	char	*wconv;
	int		i;

	wconv = NULL;
	oct = NULL;
	i = 0;
	while (ncar)
	{
		n = ft_get_nbits(*(wchar + i));
		if (!(oct = ft_getoct(*(wchar + i), ft_getmask(n))))
			return (NULL);
		n = ft_get_noct(n);
		if (!(oct = ft_convoct(oct, n)))
			return (NULL);
		if (!(wconv = ft_strjoindfree(wconv, oct)))
			return (NULL);
		i++;
		ncar--;
	}
	return (wconv);
}

static char			*apply_preci(char *conv, char *info, int len)
{
	int		sizep;
	char	*preci;

	preci = NULL;
	sizep = ft_getpreci(info);
	if (sizep > len)
	{
		if (!(preci = (char *)ft_memalloc(sizeof(char) * (sizep - len))))
			return (NULL);
	}
	else if (sizep != -1)
		return (ft_strsub(conv, 0, sizep - 1));
	if (preci)
		return (ft_strjoindfree(preci, conv));
	return (conv);
}

char				*ft_apply_wchar(char *info, int adj, va_list ap)
{
	int		*wchar;
	int		ncar;
	char	*conv;
	int		len;

	conv = NULL;
	wchar = va_arg(ap, int *);
	ncar = get_ncar(wchar);
	if (!(conv = apply_wchar(ncar, wchar)))
		return (NULL);
	len = ft_strlen(conv);
	if (!(conv = apply_preci(conv, info, len)))
		return (NULL);
	return (ft_apply_widtchar(info, conv, adj));
}
