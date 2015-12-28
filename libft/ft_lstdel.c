/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:17:13 by lgosse            #+#    #+#             */
/*   Updated: 2015/11/28 14:55:46 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next_tmp;

	if (alst != NULL)
	{
		next_tmp = NULL;
		while (*alst != NULL)
		{
			next_tmp = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = next_tmp;
		}
		alst = NULL;
	}
}
