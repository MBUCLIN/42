/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmidadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:10:57 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/10 16:11:00 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strmidadd(char *tocut, char *toadd, int i)
{
	char	*p1;
	char	*p2;

	if (i == 0)
		return (ft_strjoindfree(toadd, tocut));
	if (!(p1 = ft_strsub(tocut, 0, i)))
		return (NULL);
	if (!(p2 = ft_strsub(tocut, i, ft_strlen(tocut) - i)))
		return (NULL);
	free(tocut);
	if (!(toadd = ft_strjoindfree(p1, toadd)))
		return (NULL);
	if (!(toadd = ft_strjoindfree(toadd, p2)))
		return (NULL);
	return (toadd);
}
