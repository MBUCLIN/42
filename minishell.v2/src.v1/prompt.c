/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 13:54:57 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/07 14:51:40 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

char		*create_prompt(int opt, char **env)
{
	char		*name;

	if (opt == 1)
		name = ft_srchenv("PWD=", env);
	else if (opt == 2)
	{
		if ((name = ft_srchenv("USER=", env)) == NULL)
			return (ft_strdup("$> "));
	}
	else if (opt == 4)
	{
		if ((name = ft_srchenv("LOGNAME=", env)) == NULL)
			return (ft_strdup("$> "));
	}
	return (ft_strjoin(name, " "));
}

char		*search_prompt(int option, char **env)
{
	if (option == 0)
		return (ft_strdup("$> "));
	return (create_prompt(option, env));
}

int			search_option(char *option)
{
	if (option)
	{
		if (!ft_strcmp(option, "-p"))
			return (1);
		else if (!ft_strcmp(option, "-u"))
			return (2);
		else if (!ft_strcmp(option, "-l"))
			return (4);
	}
	return (0);
}
