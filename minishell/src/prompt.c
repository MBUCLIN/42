/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:08:16 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/02 17:59:03 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

static char		*prompt_option(char *opt, char **env)
{
	if (!ft_strcmp("-u", opt))
		return (ft_srchenv("USER=", env));
	else if (!ft_strcmp("-l", opt))
		return (ft_srchenv("LOGNAME=", env));
	else if (!ft_strcmp("-p", opt))
		return (getcwd(NULL, 0));
	return (NULL);
}

char			*search_prompt(char *opt, char **env)
{
	char		*prompt;

	prompt = NULL;
	if (opt == NULL)
	{
		if ((prompt = ft_strdup("$>")) == NULL)
			return (NULL);
		return (prompt);
	}
	if (ft_strlen(opt) == 2 && opt[0] == '-')
	{
		if ((prompt = prompt_option(opt, env)) == NULL)
			return (ft_strdup("$>"));
		return (prompt);
	}
	return (ft_strdup(opt));
}

char			*change_prompt(t_shell *shell)
{
	if (shell->opt)
	{
		free(shell->prompt);
		return (getcwd(NULL, 0));
	}
	return (shell->prompt);
}
