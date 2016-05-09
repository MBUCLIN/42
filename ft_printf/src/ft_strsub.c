/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:10:23 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/10 14:02:06 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_strsub(const char *tosub, int sta, int size)
{
	char	*sub;
	int		i;

	i = 0;
	sub = NULL;
	if (size > ft_strlen(tosub) - sta)
	{
		size = ft_strlen(tosub) - sta;
		if (size < 1)
			return (NULL);
	}
	if (!(sub = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	sub[size] = 0;
	while (i < size && tosub[sta])
	{
		sub[i] = tosub[sta];
		i++;
		sta++;
	}
	return (sub);
}
