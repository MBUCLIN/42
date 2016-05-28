/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltabswapstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 15:05:10 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/28 15:10:40 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_deltabswapstr(char **env, char *del, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (!ft_strcmp(env[i], del))
		{
			free(env[i]);
			ft_swaptabstr(&env, i, len);
		}
		i++;
	}
	return (env);
}
