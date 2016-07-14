/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 13:20:42 by mbuclin           #+#    #+#             */
/*   Updated: 2016/07/12 14:24:24 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int			create_pathenv(char ***cpy, char *name, char *content)
{
	char		*new;

	if ((new = ft_strjoin(name, content)) == NULL)
		return (-1);
	free(content);
	if ((*cpy = ft_addstrtotab(*cpy, new)) == NULL)
		return (-1);
	free(new);
	return (0);
}

int			create_pathbinenv(char ***cpy)
{
	char	*new;
	char	*path;

	if ((path = ft_strdup("PATH=")) == NULL)
		return (-1);
	if ((new = read_etcpaths()) == NULL)
		return (-1);
	if ((new = ft_strjoindfree(path, new)) == NULL)
		return (-1);
	if ((*cpy = ft_addstrtotab(*cpy, new)) == NULL)
		return (-1);
	free(new);
	return (0);
}

int			create_underscore(char ***cpy, char *name, char *content)
{
	char		*new;

	if ((content = ft_strjoinfree(content, "./minishell")) == NULL)
		return (-1);
	if ((new = ft_strjoin(name, content)) == NULL)
		return (-1);
	free(content);
	if ((*cpy = ft_addstrtotab(*cpy, new)) == NULL)
		return (-1);
	free(new);
	return (0);
}

char		**recreate_env(void)
{
	char		**new;
	int			check[4];

	new = NULL;
	check[0] = create_pathbinenv(&new);
	check[1] = create_pathenv(&new, "PWD=", getcwd(NULL, 0));
	check[2] = create_pathenv(&new, "OLDPWD=", getcwd(NULL, 0));
	check[3] = create_underscore(&new, "_=", getcwd(NULL, 0));
	if (check[0] == -1 || check[1] == -1 || check[2] == -1 || check[3] == -1)
		return (NULL);
	return (new);
}
