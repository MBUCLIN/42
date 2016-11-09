/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 14:57:32 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/30 18:51:05 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list		*tmp;

	if (new == NULL)
		return ;
	if ((*alst) == NULL)
	{
		(*alst) = new;
		return ;
	}
	tmp = (*alst);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}
