/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltabstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:12:02 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/27 16:15:29 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_deltabstr(char **del, int pos)
{
	while (pos)
	{
		if (del[pos])
			free(del[pos]);
		pos--;
	}
	free(del);
	return (NULL);
}
