/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:55:02 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/02 18:14:24 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*toret;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!(toret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	toret[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	if (s1 != NULL)
		while (s1[++i])
		{
			toret[j] = s1[i];
			j++;
		}
	i = -1;
	if (s2 != NULL)
		while (s2[++i])
		{
			toret[j] = s2[i];
			j++;
		}
	return (toret);
}
