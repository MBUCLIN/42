/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupprintf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:13:28 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/10 12:13:30 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_strdupprintf(const char *src, int size)
{
	char	*dup;

	dup = NULL;
	if (!(dup = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memcpy(dup, src, size);
	dup[size] = 0;
	return (dup);
}
