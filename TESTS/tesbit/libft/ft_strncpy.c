/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:14:16 by mbuclin           #+#    #+#             */
/*   Updated: 2015/11/30 17:25:05 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	ft_bzero(dest, n);
	if (ft_strlen(src) < n)
	{
		return (ft_strcpy(dest, src));
	}
	return (ft_memcpy(dest, src, n));
}
