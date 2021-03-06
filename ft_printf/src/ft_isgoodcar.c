/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgoodcar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:41:26 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/15 13:41:27 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_isgoodcar(int c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ' ||\
		c == '.' || c == 'l' || c == 'h' || c == 'z' || c == 'j' ||\
		ft_isconv(c))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
