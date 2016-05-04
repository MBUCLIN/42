/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_major.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:14:56 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/04 14:53:37 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		need_major(struct stat buf, int mode)
{
	if ((!(mode & 020000) && !(mode & 060000)) || mode & 040000)
		return (0);
	return (major(buf.st_rdev));
}

int		need_minor(struct stat buf, int mode)
{
	if ((!(mode & 020000) && !(mode & 060000)) || mode & 040000)
		return (0);
	return (minor(buf.st_rdev));
}
