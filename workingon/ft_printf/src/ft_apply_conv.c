/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:55:22 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/24 15:25:51 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*get_s(char *s, int len)
{
	char	*ret;
	int		i;

	ret = NULL;
	if (!(ret = (char *)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = *(s + i);
	return (ret);
}

static char		*get_convs(int len, int adj, char *s, char *info)
{
	char	*preci;
	int		sizep;

	sizep = ft_getpreci(info);
	if (s == NULL)
		return (NULL);
	preci = NULL;
	if (sizep > len)
	{
		if (!(preci = (char *)ft_memalloc(sizeof(char) * (sizep - len))))
			return (NULL);
	}
	else if (sizep != -1)
		if (!(s = ft_strsub(s, 0, sizep)))
			return (NULL);
	if (preci != NULL)
		ft_memset(preci, ' ', sizep - len);
	if (len == 0 || !(s = ft_strjoindfree(preci, s)))
		return (NULL);
	return (ft_apply_widtchar(info, s, adj));
}

static char		*apply_convs(char *info, int adj, va_list ap)
{
	char	*s;
	int		len;

	s = NULL;
	s = va_arg(ap, char *);
	if (s == NULL)
		return (get_convs(5, adj, ft_strdup("(nul)"), info));
	len = ft_string_len(s);
	return (get_convs(len, adj, get_s(s, len), info));
}

char			*ft_apply_conv(char *info, va_list ap, int lm)
{
	int		c;
	int		adj;

	adj = ft_getadj(info);
	c = info[ft_strlen(info) - 1];
	if ((c == 'c' || c == '%') && lm != 'l')
		return (ft_apply_charc(info, adj, ap));
	else if (c == 's' && lm != 'l')
		return (apply_convs(info, adj, ap));
	else if (c == 'p' || c == 'P')
		return (ft_apply_convp(info, adj, ap));
	else if (c == 'C' || (lm == 'l' && c == 'c'))
		return (ft_apply_wint(info, adj, ap));
	return (ft_apply_wchar(info, adj, ap));
}
