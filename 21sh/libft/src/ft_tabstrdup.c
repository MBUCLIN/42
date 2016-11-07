/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 17:21:23 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/08 14:46:25 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		**ft_tabstrdup(char **tab)
{
	int		i;
	char	**dest;
	int		len;

	if (tab == NULL)
		return (NULL);
	len = ft_tabstrlen(tab);
	if ((dest = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	dest[i] = NULL;
	while (tab[i])
	{
		if ((dest[i] = ft_strdup(tab[i])) == NULL)
		{
			ft_deltabstr(dest, len);
			return (NULL);
		}
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
