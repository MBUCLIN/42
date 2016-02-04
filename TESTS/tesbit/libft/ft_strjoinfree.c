/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:55:02 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/06 15:13:36 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoinfree(char *s1, char const *s2)
{
	char	*toret;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!(toret = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	if (s1)
		ft_strcpy(toret, s1);
	if (s2)
		ft_strcpy((toret + ft_strlen(s1)), s2);
	toret[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	if (s1)
		free(s1);
	s1 = NULL;
	return (toret);
}
