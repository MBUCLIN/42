/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:45:59 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/02 17:21:36 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*get_str_time(time_t temps)
{
	char	*str_time;
}

char		*get_line_grus_name(t_info *node)
{
	char		*grus;

	grus = NULL;
	if (!(grus = ft_strdup(node->us_name)))
		return (NULL);
	if (!(grus = ft_strncadd(grus, 2, ' ')))
		return (NULL);
	return (ft_strjoindfree(grus, node->gr_name));
}

char		*get_line_print(t_all *node, int sizelenm)
{
	char		*line;

	line = NULL;
	if (!(line = get_line_mode(node->info->mode)))
		return (NULL);
	if (!(line = ft_strncadd(line, 2, ' ')))
		return (NULL);
	if (!(line = ft_strjoindfree(line, ft_itoa(node->info->hardl))))
		return (NULL);
	if (!(line = ft_strncadd(line, 1, ' ')))
		return (NULL);
	if (!(line = ft_strjoindfree(line, get_line_grus_name(node->info))))
		return (NULL);
	if (!(line = ft_strncadd(line, sizelenm - ft_nlen(node->info->size, ' '))))
		return (NULL);
	if (!(line = ft_strjoindfree(line, ft_itoa(node->info->size))))
		return (NULL);
	if (!(line = ft_strjoindfree(line, get_strtime(node->info->time))))
		return (NULL);
	if (!(line = ft_strncadd(line, 1, ' ')))
		return (NULL);
	if (!(line = ft_strjoindfree(line, node->name->name)))
		return (NULL);
	return (line);
}
