/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:13:29 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/28 17:38:36 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

char		**add_env(char **env, char **arg)
{
	char	*bad;
	int		i;
	int		len;

	if ((bad = bad_arg(arg)))
	{
		ft_perror("setenv: illegal name or value -- ", bad);
		ft_putendl_fd(2 ,"usage: setenv [NAME=value ...]");
		return (env);
	}
	len = ft_tabstrlen(env) - 1;
	i = 0;
	while (arg[++i])
		if (ft_strchr(arg[i], '=') == NULL)
		{
			errorformat(arg[i]);
			return (ft_deltabstr(env, len + 1));
		}
		else if ((env = ft_addstrtotab(env, arg[i])) == NULL)
			return (NULL);
	while (env[++len])
		ft_printf("setenv:	%s\n", env[len]);
	ft_puttab(env);
	return (env);
}

char		**rem_env(char **env, char **arg)
{
	char		*bad;
	int			len;
	int			i;

	if ((bad = bad_arg(arg)))
	{
		ft_perror("unsetenv: illegal option -- ", bad);
		ft_putendl_fd(2, "usage: unsetenv [NAME=value ...]");
		return (env);
	}
	i = 1;
	len = ft_tabstrlen(env);
	while (arg[i])
	{
		env = ft_deltabswapstr(env, arg[i], len--);
		i++;
	}
	return (env);
}
