/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:46:41 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/04 13:53:43 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_maxl		*set_maxl(t_maxl *max)
{
	max->hlen_m = 0;
	max->ulen_m = 0;
	max->glen_m = 0;
	max->slen_m = 0;
	max->max_min = 0;
	max->max_maj = 0;
	return (max);
}
t_maxl				*get_len_max(t_all *head)
{
	t_maxl		*ret;
	t_all		*tmp;
	int			len;

	if (!(ret = (t_maxl *)malloc(sizeof(t_maxl))))
		return (NULL);
	tmp = head;
	ret = set_maxl(ret);
	while (tmp)
	{
		if (ret->hlen_m < (len = ft_nlen(tmp->info->hardl)))
			ret->hlen_m = len;
		if (ret->ulen_m < (len = ft_strlen(tmp->info->us_name)))
			ret->ulen_m = len;
		if (ret->glen_m < (len = ft_strlen(tmp->info->gr_name)))
			ret->glen_m = len;
		if (ret->slen_m < (len = ft_nlen(tmp->info->size)))
			ret->slen_m = len;
		if (tmp->info->min || tmp->info->maj)
		{
			if (ret->max_min < (len = ft_nlen(tmp->info->min)))
				ret->max_min = len;
			if (ret->max_maj < (len = ft_nlen(tmp->info->maj)))
				ret->max_maj = len;
			if (ret->slen_m <\
				(len = ft_nlen(tmp->info->maj) + 2 + ft_nlen(tmp->info->min)))
				ret->slen_m = len;
		}
		tmp = tmp->next;
	}
	return (ret);
}
