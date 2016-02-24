/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_widtchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:17:26 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/24 16:32:39 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_apply_widtchar(char *info, char *conv, int adj)
{
	int		sizew;
	char	*width;
	int		len;

	len = ft_strlen(conv);
	width = NULL;
	sizew = ft_getwidth(info);
	free(info);
	if (sizew > len)
		if (!(width = (char *)ft_memalloc(sizeof(char) * (sizew - len))))
			return (NULL);
	if (!width)
		return (conv);
	ft_memset(width, ' ', sizew - len);
	if (adj == 'r')
		return (ft_strjoindfree(conv, width));
	return (ft_strjoindfree(width, conv));
}
