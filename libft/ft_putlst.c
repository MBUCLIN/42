/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 18:00:10 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/30 18:01:08 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_putlst(t_list *head)
{
	t_list		*tmp;

	tmp = head;
	while (tmp)
	{
		ft_putendl((char *)tmp->content);
		tmp = tmp->next;
	}
}
