/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:59:00 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/04 17:50:05 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

t_list		*get_env(t_list *env)
{
	static t_list		*save;

	if (env == NULL)
		return (save);
	else
		save = env;
	return (env);
}

char		*ft_getenv(char *variable)
{
	t_list		*env;
	t_list		*tmp;
	int			len;

	env = get_env(NULL);
	tmp = env;
	len = ft_strlen(variable);
	while (tmp)
	{
		if (!ft_memcmp(variable, tmp->content, len))
			return (tmp->content + ft_strlen(variable));
		tmp = tmp->next;
	}
	return (NULL);
}
