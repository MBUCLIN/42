/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:13:29 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/31 15:26:30 by mbuclin          ###   ########.fr       */
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
		ft_putendl_fd(2, "usage: setenv [NAME=value ...]");
		return (env);
	}
	len = ft_tabstrlen(env) - 1;
	i = 0;
	ft_puttab(arg);
	while (arg[++i])
	{
		if ((env = ft_addstrtotab(env, arg[i])) == NULL)
			return (NULL);
		ft_printf("setenv: %s\n", arg[i]);
	}
	ft_puttab(env);
	return (env);
}

char		**rem_env(char **env, char **arg)
{
	char		*var;
	int			len;
	int			i;

	i = 1;
	len = ft_tabstrlen(env);
	while (arg[i])
	{
		if ((var = get_var(arg[i], env)) == NULL)
		{
			ft_perror("unsetenv: illegal name -- ", arg[i]);
			ft_putendl_fd(2, "usage: unsetenv [NAME ...]");
			return (env);
		}
		env = ft_deltabswapstr(env, var, len--);
		free(var);
		var = NULL;
		i++;
	}
	return (env);
}
