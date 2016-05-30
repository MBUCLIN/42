/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotabstrfree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 13:34:34 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/30 18:40:10 by mbuclin          ###   ########.fr       */
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
	i = -1;
	while (tmp)
	{
		if ((tab[++i] = ft_strdup((char *)tmp->content)) == NULL)
		{
			ft_deltabstr(tab, len);
			ft_lstdel(&head, ft_delstrcontent);
			return (NULL);
		}
		tmp = tmp->next;
	}
	tab[i] = NULL;
	ft_lstdel(&head, ft_delstrcontent);
	return (tab);
}
