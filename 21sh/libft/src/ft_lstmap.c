/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:11:20 by mbuclin           #+#    #+#             */
/*   Updated: 2015/12/01 16:11:22 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst_cpy;
	t_list	*tmp_cpy;

	lst_cpy = NULL;
	tmp_cpy = NULL;
	if (!(lst_cpy = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	*lst_cpy = *f(lst_cpy);
	tmp_cpy = lst_cpy;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp_cpy->next = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		tmp_cpy = tmp_cpy->next;
		*tmp_cpy = *f(tmp_cpy);
		lst = lst->next;
	}
	return (lst_cpy);
}
