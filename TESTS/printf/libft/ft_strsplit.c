/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:54:37 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/02 17:38:33 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_nword(const char *s, char c)
{
	int		n;
	int		i;

	i = 0;
	n = 0;
	if (s[0] != c)
	{
		n++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			n++;
		i++;
	}
	return (n);
}

static int		find_sword(const char *s, unsigned int i, char c)
{
	int		size;

	size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

static char		*complete_tab(char *tab, const char *s, int i, char c)
{
	if (!(tab = ft_strsub(s, i, find_sword(s, i, c))))
		return (NULL);
	return (tab);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * find_nword(s, c))))
		return (NULL);
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
		{
			tab[j] = complete_tab(tab[j], s, i, c);
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
