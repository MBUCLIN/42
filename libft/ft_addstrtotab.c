/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstrtotab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:37:06 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/09 16:49:19 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		**ft_addstrtotab(char **tab, char *str)
{
	int		len;
	char	**new;
	int		i;

	if (tab)
		len = ft_tabstrlen(tab) + 1;
	else
		len = 1;
	if ((new = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (ft_deltabstr(tab, len));
	i = 0;
	if (tab)
		while (tab[i])
		{
			new[i] = tab[i];
			i++;
		}
	if ((new[i++] = ft_strdup(str)) == NULL)
	{
		ft_deltabstr(tab, len);
		return (ft_deltabstr(new, i));
	}
	free(tab);
	new[i] = NULL;
	return (new);
}
