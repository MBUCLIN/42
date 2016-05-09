/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:45:59 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/09 18:28:48 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*get_str_time(char *line, t_all *node)
{
	long	tact;
	long	tfile;
	char	*date;

	tact = time(&tact);
	tfile = node->info->time;
	if (!(line = ft_strncadd(line, 1, ' ')))
		return (NULL);
	if (tfile > tact || tfile < tact - SX_M)
	{
		if (!(date = get_date_year(tfile)))
		{
			free(line);
			return (NULL);
		}
	}
	else
	{
		if (!(date = get_date(tfile)))
		{
			free(line);
			return (NULL);
		}
	}
	return (ft_strjoindfree(line, date));
}

char		*get_line_grus_name(t_info *node, t_maxl *max)
{
	char		*grus;

	grus = NULL;
	if (!(grus = ft_strdup(node->us_name)))
		return (NULL);
	if (!(grus = ft_strncadd(grus, 2 +\
		(max->ulen_m - ft_strlen(node->us_name)), ' ')))
		return (NULL);
	if (!(grus = ft_strjoindfree(grus, ft_strdup(node->gr_name))))
		return (NULL);
	if (!(grus = ft_strncadd(grus, 2 +\
		(max->glen_m - ft_strlen(node->gr_name)), ' ')))
		return (NULL);
	return (grus);
}

char		*get_line_minmaj(char *line, t_info *node, t_maxl *max)
{
	if (!(line = ft_strncadd(line, max->slen_m -\
		(ft_nlen(node->maj) + max->max_min + 2) +\
		(max->max_maj - ft_nlen(node->maj)), ' ')))
		return (NULL);
	if (!(line = ft_strjoindfree(line, ft_itoa(node->maj))))
		return (NULL);
	if (!(line = ft_strjoindfree(line, ft_strdup(", "))))
		return (NULL);
	if (!(line = ft_strncadd(line, max->max_min - ft_nlen(node->min), ' ')))
		return (NULL);
	if (!(line = ft_strjoindfree(line, ft_itoa(node->min))))
		return (NULL);
	return (line);
}

char		*get_size_or_minmaj(char *line, t_info *node, t_maxl *max)
{
	if (((node->mode & 02000) || (node->mode & 060000)) &&\
		!(node->mode & 040000))
		return (get_line_minmaj(line, node, max));
	if (!(line = ft_strncadd(line, max->slen_m - ft_nlen(node->size), ' ')))
		return (NULL);
	if (!(line = ft_strjoindfree(line, ft_itoa(node->size))))
		return (NULL);
	return (line);
}

char		*get_line_print(t_all *node, t_maxl *max)
{
	char		*line;

	line = NULL;
	if (!(line = get_line_mode(node->info->mode)))
		return (NULL);
	if (!(line = ft_strncadd(line, 2 +\
		(max->hlen_m - ft_nlen(node->info->hardl)), ' ')))
		return (NULL);
	if (!(line = ft_strjoindfree(line, ft_itoa(node->info->hardl))))
		return (NULL);
	if (!(line = ft_strncadd(line, 1, ' ')))
		return (NULL);
	if (!(line = ft_strjoindfree(line, get_line_grus_name(node->info, max))))
		return (NULL);
	if (!(line = get_size_or_minmaj(line, node->info, max)))
		return (NULL);
	if (!(line = get_str_time(line, node)))
		return (NULL);
	if (!(line = ft_strncadd(line, 1, ' ')))
		return (NULL);
	if (!(line = ft_strjoindfree(line, ft_strdup(node->name->name))))
		return (NULL);
	return (line);
}
