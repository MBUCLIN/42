/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isconvc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:14:56 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/10 13:51:37 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_isconvc(int c)
{
	if (c == 'c' || c == 's' || c == '%' ||\
		c == 'S' || c == 'C' || c == 'p')
		return (1);
	return (0);
}
