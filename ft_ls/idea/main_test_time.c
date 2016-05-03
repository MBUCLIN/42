/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:20:10 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/03 13:55:09 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	char			*file;
	char			*temps;
	char			*fullt;
	char			*datet;
	char			*ret;
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
	free(file);
	ft_putendl(temps);
	if (!(fullt = ft_strsub(temps, 4, 12)))
		return (0);
	ft_putendl(fullt);
	free(fullt);
	if (!(datet = ft_strsub(temps, 4, 6)))
		return (0);
	if (!(datet = ft_strncadd(datet, 2, ' ')))
		return (0);
	if (!(datet = ft_strjoindfree(datet, ft_strsub(temps, 20, 4))))
		return (0);
	ft_putendl(datet);
	free(datet);
	return (1);
}
