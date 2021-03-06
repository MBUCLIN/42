/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:11:33 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/20 13:35:14 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

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

static char		*complete_tab(char **tab, const char *s, int i, char c)
{
	if (!(*tab = ft_strsub(s, i, find_sword(s, i, c))))
		return (NULL);
	return (*tab);
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
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * find_nword(s, c) + 1)))
		return (NULL);
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
		{
			if (!(tab[j] = complete_tab((tab + j), s, i, c)))
				return (ft_deltabstr(tab, find_nword(s, c)));
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
