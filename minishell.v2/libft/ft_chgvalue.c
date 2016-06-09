/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chgvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 12:40:05 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/09 16:16:13 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			**ft_chgvalue(char *name, char *nvalue, char **tab)
{
	int			i;
	char		*new;

	i = 0;
	if (nvalue == NULL)
		return (NULL);
	if ((new = ft_strjoin(name, nvalue)) == NULL)
		return (NULL);
	while (tab[i])
	{
		if (ft_strstr(tab[i], name))
		{
			free(tab[i]);
			if ((tab[i] = ft_strdup(new)) == NULL)
				return (NULL);
			free(new);
			return (tab);
		}
		i++;
	}
	free(new);
	return (tab);
}
