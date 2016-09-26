/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:55:34 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/27 16:28:59 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)(c))
			return ((unsigned char *)(s + i));
		i++;
	}
	return (NULL);
}
