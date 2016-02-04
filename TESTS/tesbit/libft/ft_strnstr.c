/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:39:46 by mbuclin           #+#    #+#             */
/*   Updated: 2015/12/14 13:59:27 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s2[len])
		len++;
	if (len == 0 && s2 != NULL)
		return ((char *)s1);
	while (s1[i] && i + len <= n)
	{
		if (ft_memcmp((s1 + i), s2, len) == 0)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
