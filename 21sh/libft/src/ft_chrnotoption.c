/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrnotoption.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:44:53 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/04 17:11:02 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_chrnotoption(char *chr, char *option)
{
	int		i;

	i = 0;
	while (chr[i])
	{
		if (!ft_isoption(chr[i], option))
			return (chr[i]);
		i++;
	}
	return (0);
}
