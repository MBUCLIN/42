/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotabstrfree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 13:34:34 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/06 15:29:56 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		**ft_lsttotabstrfree(t_list *head)
{
	int		i;
	t_list	*tmp;
	char	**tab;
	int		len;

	len = ft_lstlen(head);
	if ((tab = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	tmp = head;
	i = 0;
	while (tmp)
	{
		tab[i + 1] = NULL;
		if ((tab[i] = ft_strdup((char *)tmp->content)) == NULL)
		{
			ft_deltabstr(tab, len);
			return (NULL);
		}
		tab[tmp->content_size] = 0;
		tmp = tmp->next;
		i++;
	}
	ft_lstdel(&head, ft_delstrcontent);
	tab[i] = NULL;
	return (tab);
}
