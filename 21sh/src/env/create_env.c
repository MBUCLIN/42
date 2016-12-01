/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:06:16 by mbuclin           #+#    #+#             */
/*   Updated: 2016/12/01 13:18:35 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void		add_to_env(const char *name_var)
{
	long		n;
	char		*chr;
	char		*name;
	char		*var;

	if ((chr = ft_strchr(name_var, '=')) == NULL)
		return ;
	n = ((long)chr - (long)name_var) + 1;
	if ((name = ft_strsub(name_var, 0, n)) == NULL)
		ft_exitshell("21sh", ERRMALLOC, NULL);
	if ((var = ft_strsub(name_var, n, ft_strlen(name_var))) == NULL)
		ft_exitshell("21sh", ERRMALLOC, NULL);
	if ((ft_setenv(name, var)) == NULL)
		ft_exitshell("21sh", ERRMALLOC, NULL);
	free(name);
	free(var);
}

static char		*shlvl_increment(const char *shlvl)
{
	char		*name;
	int			value;
	char		*var;

	if ((name = ft_strdup("SHLVL=")) == NULL)
		return (NULL);
	if (shlvl != NULL)
	{
		if ((var = ft_strsub(shlvl, 6, ft_strlen(shlvl))) == NULL)
			return (NULL);
		value = ft_atoi(var);
		value += 1;
		free(var);
	}
	else
		value = 1;
	if ((var = ft_itoa(value)) == NULL)
		return (NULL);
	if ((name = ft_strjoinfree(name, var)) == NULL)
		return (NULL);
	free(var);
	return (name);
}

static void		create_fromenv(const char **env)
{
	int			i;
	char		*shlvl;
	int			found;

	i = 0;
	found = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], "SHLVL=") == NULL)
			add_to_env(env[i]);
		else
		{
			if ((shlvl = shlvl_increment(env[i])) == NULL)
				ft_exitshell("21sh", ERRMALLOC, NULL);
			add_to_env(shlvl);
			free(shlvl);
			found = 1;
		}
		i++;
	}
	if (found)
		shlvl_increment(NULL);
}

static void		create_known(void)
{
	ft_setenv(FTSHLVL, "1");
	create_pwd(FTPWD);
	create_path(FTPATH);
	ft_setenv(FTHOME, ft_gethome());
}

void			create_env(void)
{
	extern char		**environ;

	if (environ == NULL || environ[0] == NULL)
		create_known();
	else
		create_fromenv((const char **)environ);
}
