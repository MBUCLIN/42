/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:56:52 by mbuclin           #+#    #+#             */
/*   Updated: 2015/12/08 16:27:58 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *(unsigned char *)(src + i) != (unsigned char)c)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	if (i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		return (dest + i + 1);
	}
	return (NULL);
}
