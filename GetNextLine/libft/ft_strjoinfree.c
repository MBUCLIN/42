/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:55:02 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/02 18:14:50 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char const *s2)
{
	char	*toret;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!(toret = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	if (s1)
		while (s1[++i])
		{
			toret[j] = s1[i];
			j++;
		}
	i = -1;
	if (s2)
		while (s2[++i])
		{
			toret[j] = s2[i];
			j++;
		}
	free(s1);
	s1 = NULL;
	toret[j] = '\0';
	return (toret);
}
