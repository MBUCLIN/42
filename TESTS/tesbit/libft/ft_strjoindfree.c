/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:22:18 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/19 14:31:25 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoindfree(char *s1, char *s2)
{
	char		*output;
	int			size;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(output = (char *)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	if (s1)
	{
		ft_strcpy(output, s1);
		free(s1);
	}
	if (s2)
	{
		ft_strcat(output, s2);
		free(s2);
	}
	output[size] = '\0';
	return (output);
}
