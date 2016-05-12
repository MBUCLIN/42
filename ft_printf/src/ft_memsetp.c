/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsetp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:19:12 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/12 17:19:14 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_memsetp(void *p, int c, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		*(unsigned char *)(p + i) = c;
}
