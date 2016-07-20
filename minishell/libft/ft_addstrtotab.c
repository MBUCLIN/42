/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstrtotab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:37:06 by mbuclin           #+#    #+#             */
/*   Updated: 2016/07/18 13:31:47 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		**ft_addstrtotab(char **tab, char *str)
{
	int		len;
	char	**new;
	int		i;

	len = ft_tabstrlen(tab) + 1;
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
	ft_deltabstr(tab, len);
	new[i] = NULL;
	return (new);
}
