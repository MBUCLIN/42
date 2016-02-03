/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:16:32 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/03 15:24:32 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_info(char *conv)
{
	unsigned char	info;
	int				i;

	info = 0b00000001;
	i = 0;
	while (conv[i])
	{
		if (conv[i] == '#')
			info = info + 0b10000000;
		else if (conv[i] == '0')
			info = info + 0b01000000;
		else if (conv[i] == '-')
			info = info + 0b00100000;
		else if (conv[i] == ' ')
			info = info + 0b00010000;
		else if (conv[i] == '+')
			info = info + 0b00001000;
		else if (conv[i] == '*')
			info = info + 0b00000100;
		else if (conv[i] == '.')
			info = info + 0b00000010;
		i++;
	}
	return (info);
}
