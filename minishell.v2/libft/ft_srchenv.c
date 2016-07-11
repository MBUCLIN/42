/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srchenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:25:47 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/29 15:30:43 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_srchenv(char *varname, char **env)
{
	int		i;
	int		len;
	char	*varcontent;

	i = 0;
	len = ft_strlen(varname);
	if (env)
		while (env[i])
		{
			if ((varcontent = ft_strstr(env[i], varname)))
			{
				if (ft_strstr(env[i],"_=") && ft_strcmp(varname, "_="))
				{
					i++;
					continue ;
				}
				return (varcontent + ft_strlen(varname));
			}
			i++;
		}
	return (NULL);
}
