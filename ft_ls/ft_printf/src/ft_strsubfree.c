/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:23:03 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/10 12:23:12 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_strsubfree(char *tosub, int sta, int size)
{
	char	*sub;
	int		i;

	i = 0;
	sub = NULL;
	if (size > ft_strlen(tosub) - sta)
		size = ft_strlen(tosub) - sta;
	else if (!(sub = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	sub[size] = 0;
	while (i < size && tosub[sta])
	{
		sub[i] = tosub[sta];
		i++;
		sta++;
	}
	free(tosub);
	tosub = NULL;
	return (sub);
}
