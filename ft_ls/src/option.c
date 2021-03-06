/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:16:42 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/09 18:57:23 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*choose_line(t_all *node, t_maxl *max, int option)
{
	if (option & OPT_L)
	{
		return (get_line_print(node, max));
	}
	return (ft_strdup(node->name->name));
}

int		after_option(char **arg, char *option)
{
	int		i;

	i = 0;
	if (!arg)
		return (0);
	while (arg[i])
	{
		if (arg[i][0] != '-')
			return (i);
		if (!ft_strcmp(arg[i], "--"))
			return (i + 1);
		if (ft_chrnotoption((arg[i] + 1), option))
			break ;
		i++;
	}
	return (i);
}
