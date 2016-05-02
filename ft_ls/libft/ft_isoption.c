/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoption.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:32:18 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/27 15:34:00 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_isoption(int c, char *option)
{
	int		i;
	int		len;

	len = ft_strlen(option);
	i = 0;
	while (option[i])
	{
		if (c == option[i])
			return (1);
		i++;
	}
	return (0);
}
