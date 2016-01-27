/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:56:33 by mbuclin           #+#    #+#             */
/*   Updated: 2015/11/26 16:56:53 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*toret;

	i = 0;
	toret = NULL;
	if (s && f)
		if ((toret = ft_strnew(ft_strlen(s))))
			while (s[i])
			{
				toret[i] = f(i, s[i]);
				i++;
			}
	return (toret);
}
