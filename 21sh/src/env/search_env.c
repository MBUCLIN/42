/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:59:00 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/03 15:50:34 by mbuclin          ###   ########.fr       */
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

	env = get_env(NULL);
	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(variable, tmp->content))
			return (tmp->content + ft_strlen(variable));
		tmp = tmp->next;
	}
	return (NULL);
}
