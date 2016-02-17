/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:32:54 by mbuclin           #+#    #+#             */
/*   Updated: 2015/12/13 15:20:48 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (dst[i])
		i++;
	k = 0;
	while (src[k])
		k++;
	if (i < size)
	{
		ft_strncat(dst, src, size - i - 1);
		return (i + ft_strlen(src));
	}
	return (size + k);
}
