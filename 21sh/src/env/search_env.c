/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:59:00 by mbuclin           #+#    #+#             */
/*   Updated: 2016/12/01 13:19:04 by mbuclin          ###   ########.fr       */
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

char		*ft_setenv(char *name, char *value)
{
	t_list		*env;
	t_list		*tmp;
	char		*join;

	env = get_env(NULL);
	if ((join = ft_strjoin(name, value)) == NULL)
		return (NULL);
	if (env == NULL)
	{
		if ((env = ft_lstnew(join, ft_strlen(join))) == NULL)
			return (NULL);
		free(join);
		get_env(env);
		return (env->content);
	}
	tmp = env;
	while (tmp->next)
		tmp = tmp->next;
	if ((tmp->next = ft_lstnew(join, ft_strlen(join))) == NULL)
		return (NULL);
	free(join);
	get_env(env);
	return (tmp->next->content);
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

void		ft_displayenv(void)
{
	t_list		*env;
	t_list		*tmp;

	env = get_env(NULL);
	tmp = env;
	while (tmp)
	{
		ft_putendl(tmp->content);
		tmp = tmp->next;
	}
}
