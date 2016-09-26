/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltabswapstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 15:05:10 by mbuclin           #+#    #+#             */
/*   Updated: 2016/09/26 15:52:49 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_deltabswapstr(char **env, char *del, int len)
{
	int		i;

	i = 0;
	ft_putendl("call");
	while (i < len)
	{
		if (!ft_strcmp(env[i], del))
		{
			free(env[i]);
			ft_putendl("before swap");
			ft_swaptabstr(&env, i, len);
			ft_putendl("after swap");
		}
		i++;
	}
	ft_putendl("return");
	return (env);
}
