/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:53:41 by mbuclin           #+#    #+#             */
/*   Updated: 2015/11/26 16:53:45 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char *s, char (*f)(char))
{
	size_t	i;
	char	*toret;

	i = 0;
	toret = NULL;
	if (s && f)
		if ((toret = ft_strnew(ft_strlen(s))))
			while (s[i])
			{
				toret[i] = f(s[i]);
				i++;
			}
	return (toret);
}
