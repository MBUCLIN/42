/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:15:24 by mbuclin           #+#    #+#             */
/*   Updated: 2015/12/15 13:57:11 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	if (!(lst = (t_list *)ft_memalloc(sizeof(*lst))))
		return (NULL);
	if (content != NULL)
	{
		if (!(lst->content = ft_memalloc(content_size)))
			return (NULL);
		lst->content = ft_memcpy(lst->content, content, content_size);
	}
	else
	{
		lst->content = NULL;
		content_size = 0;
	}
	lst->content_size = content_size;
	lst->next = NULL;
	return (lst);
}
