/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:13:35 by mbuclin           #+#    #+#             */
/*   Updated: 2015/12/15 14:29:09 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	if (!(dest = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest = ft_memcpy(dest, s, len);
	return (dest);
}
