/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_noct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:19:59 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/14 16:30:53 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_get_noct(int n)
{
	if (n <= 7)
		return (1);
	else if (n <= 11)
		return (2);
	else if (n <= 16)
		return (3);
	return (4);
}
