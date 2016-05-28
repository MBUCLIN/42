/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstrtotab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:37:06 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/28 14:45:29 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		**addstrtotab(char **tab, char *str)
{
	int		len;
	char	**new;
	int		i;

	len = ft_tabstrlen(tab) + 1;
	if ((new = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (ft_deltabstr(tab, len));
	i = 0;
	while (tab[i])
	{
		new[i + 1] = NULL;
		if ((new[i] = ft_strdup(tab[i])) == NULL)
		{
			ft_deltabstr(tab, len);
			return (ft_deltabstr(new, i));
		}
		i++;
	}
	if ((new[i] = ft_strdup(str)) == NULL)
	{
		ft_deltabstr(tab, len);
		return (ft_deltabstr(new, i));
	}
	return (new);
}
