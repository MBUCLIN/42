/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:59:44 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/26 18:20:44 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

t_path		*initiate_path(void)
{
	t_path		*path;

	if ((path = (t_path *)malloc(sizeof(t_path))) == NULL)
		return (NULL);
	if ((path->cpath = getcwd(NULL, 0)) == NULL)
	{
		free(path);
		return (NULL);
	}
	path->ppath = NULL;
	return (path);
}
t_shell		*initiate_shell(char **env, char *prompt)
{
	t_shell			*shell;

	if ((shell = (t_shell *)malloc(sizeof(t_shell))) == NULL)
		return (NULL);
	if ((shell->prompt = search_prompt(prompt, env)) == NULL)
	{
		free(shell);
		return (NULL);
	}
	shell->env = env;
	if ((shell->path = initiate_path()) == NULL)
	{
		free(shell->prompt);
		free(shell);
		return (NULL);
	}
	return (shell);
}
