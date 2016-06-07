/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 18:15:14 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/07 16:45:57 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

static char		*change_fromenv(char *arg, char **env)
{
	char	*var;
	int		i;
	int		len;
	char	*ret;

	i = ft_skpblk(arg);
	len = ft_strlen(arg) - i;
	if ((var = (char *)malloc(sizeof(char) *\
							(len + 1))) == NULL)
		return (NULL);
	var = ft_strcpy(var, arg + 1);
	var[len] = 0;
	var[len - 1] = '=';
	if ((ret = ft_srchenv(var, env)) == NULL)
		return (NULL);
	free(var);
	return (ret);
}

static char		*cut_quote(char *arg)
{
	char		*ret;
	int			len;
	int			i;
	int			j;

	len = ft_strlen(arg) - 2;
	if ((ret = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	j = 0;
	i = 1;
	while (j < len)
	{
		ret[j] = arg[i];
		j++;
		i++;
	}
	ret[j] = 0;
	return (ret);
}

char			**change_arg(char **arg, char **env)
{
	int		i;
	char	*change;

	i = 1;
	while (arg[i])
	{
		if (arg[i][0] == '$')
		{
			if ((change = change_fromenv(arg[i], env)) == NULL)
				return (NULL);
			free(arg[i]);
			arg[i] = change;
		}
		else if (arg[i][0] == '"')
		{
			if ((change = cut_quote(arg[i])) == NULL)
				return (NULL);
			free(arg[i]);
			arg[i] = change;
		}
		i++;
	}
	return (arg);
}
