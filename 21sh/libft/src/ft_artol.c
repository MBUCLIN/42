/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_artol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 13:42:30 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/20 13:52:30 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		lstdel_str(void *str, size_t len)
{
	if (ft_strlen((char *)str) == len)
		free(str);
	len = 0;
}

t_list			*ft_artol(char **array)
{
	t_list		*head;
	t_list		*tmp;
	int			i;
	int			len;

	len = ft_strlen(array[0]);
	if ((head = ft_lstnew(array[0], sizeof(char) * len)) == NULL)
		return (NULL);
	tmp = head;
	i = 1;
	while (array[i] != NULL)
	{
		len = ft_strlen(array[i]);
		if ((tmp->next = ft_lstnew(array[i], sizeof(char) * len)) == NULL)
		{
			ft_lstdel(&head, lstdel_str);
			return (NULL);
		}
		tmp = tmp->next;
		tmp->next = NULL;
		i++;
	}
	return (head);
}
