/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:54:08 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/09 17:48:07 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	if ((i = ft_strlen(s1)) < n)
	{
		n = i;
		if ((i = ft_strlen(s2)) > n)
			n = i;
	}
	return (ft_memcmp(s1, s2, n));
}
