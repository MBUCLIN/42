/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:32:20 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/07 17:18:18 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

static char		**new_arg(char ***arg, char *new)
{
	if (new == NULL)
		return (NULL);
	if ((*arg = ft_addstrtotab(*arg, new)) == NULL)
		return (NULL);
	free(new);
	new = NULL;
	return (*arg);
}

char			**get_arguments(char *command, char ***arg)
{
	int		q;
	int		i;
	int		s;

	*arg = NULL;
	i = ft_skpblk(command);
	q = 0;
	s = i;
	ft_putendl(command);
	while (command[i])
	{
		if (command[i] == '"')
			q++;
		if ((q == 0 || q % 2 == 0) && ft_isblank(command[i]))
		{
			if ((*arg = new_arg(arg, ft_strsub(command, s, i - s))) == NULL)
				return (NULL);
			i = ft_skpblk(command + i);
			s = i;
		}
		i++;
	}
	return (new_arg(arg, ft_strsub(command, s, i - s)));
}

/*char		*get_var(char *arg, char **env)
{
	char		*var;
	char		*ret;

	if ((var = ft_strjoin(arg, "=")) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		end_minishell(NULL);
	}
	if ((ret = ft_srchenv(var, env)) == NULL)
		return (NULL);
	if ((ret = ft_strjoindfree(var, ret)) == NULL)
	{
		ft_perror("minishell: malloc error", NULL);
		end_minishell(NULL);
	}
	return (ret);
}*/
