/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:20:10 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/02 18:06:48 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	char	*file;
	char	*temps;
	struct stat		buf;

	file = NULL;
	if (ac == 1)
	{
		if (!(file = ft_strdup("./")))
			return (0);
	}
	else
	{
		if (!(file = ft_strdup(av[1])))
			return (0);
	}
	if (stat(file, &buf))
	{
		free(file);
		return (0);
	}
	if (!(temps = ctime(&buf.st_mtimespec.tv_sec)))
	{
		free(file);
		return (0);
	}
	ft_putendl(temps);
	if (!(temps = ft_strsub(temps, 4, 12)))
		return (0);
	ft_putendl(temps);
	free(temps);
	return (1);
}
