/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:58:40 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/19 14:15:54 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				check_times_option(int option)
{
	int		time;
	int		mask;

	time = 0;
	mask = OPT_MU;
	if (mask & option)
		time = 0b10;
	mask >>= 1;
	if (mask & option)
		time = 0b1;
	return (time);
}

static int		condition_check_opt(int c, int opt)
{
	if (c == 'l' && !(opt & OPT_L))
		opt += OPT_L;
	else if (c == 'R' && !(opt & OPT_MR))
		opt += OPT_MR;
	else if (c == 'r' && !(opt & OPT_R))
		opt += OPT_R;
	else if (c == 'a' && !(opt & OPT_A))
		opt += OPT_A;
	else if (c == 't' && !(opt & OPT_T))
		opt += OPT_T;
	else if (c == 'u' && !(opt & OPT_U))
		opt += OPT_U;
	else if (c == 'U' && !(opt & OPT_MU))
		opt += OPT_MU;
	return (opt);
}

int				check_option(char *arg)
{
	int		i;
	int		opt;

	i = 1;
	opt = 0;
	if (arg[0] != '-')
		return (0);
	else if (arg[1] == '-' && !arg[2])
		return (0);
	while (arg[i])
	{
		if (!ft_isoption(arg[i], "lRratuU"))
			return (-1);
		opt = condition_check_opt(arg[i], opt);
		i++;
	}
	return (opt);
}

int				check_file(t_all *node, int option)
{
	int		ret;

	ret = 1;
	if (S_ISDIR(node->info->mode))
		ret = 0;
	else if (S_ISLNK(node->info->mode))
	{
		ret = 0;
		if (OPT_L & option)
			ret = 1;
	}
	if (node->info->mode == 0)
		ret = 0;
	return (ret);
}

int				check_dir(t_all *node, int option, int call)
{
	int		ret;

	ret = 0;
	if (call)
		if (!ft_strcmp(node->name->name, ".") ||\
			!ft_strcmp(node->name->name, "./") ||\
			!ft_strcmp(node->name->name, "..") ||\
			!ft_strcmp(node->name->name, "../"))
			return (0);
	if (S_ISDIR(node->info->mode))
		ret = 1;
	if (S_ISLNK(node->info->mode))
	{
		if (option & OPT_L)
			ret = 0;
		else
			ret = 1;
	}
	if (S_ISBLK(node->info->mode))
		ret = 0;
	return (ret);
}
