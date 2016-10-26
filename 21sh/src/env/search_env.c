/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:59:00 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/20 18:03:51 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

char		*search_env(char *var, t_list *env)
{
	t_list		*tmp;
	int			len;

	len = ft_strlen(var);
	tmp = env;
	while (tmp)
	{
		if (!ft_memcmp(var, tmp->content, len))
			return (tmp->content + len);
		tmp = tmp->next;
	}
	return (NULL);
}
