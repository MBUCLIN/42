/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 13:54:54 by mbuclin           #+#    #+#             */
/*   Updated: 2016/07/11 14:11:15 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_treatquote(char *str)
{
	size_t		len;
	char		*ret;

	len = ft_strlen(str);
	if (str[0] == 34 || str[0] == 39)
		len -= 2;
	if (len != ft_strlen(str))
	{
		if ((ret = ft_strsub(str, 1, len)) == NULL)
			return (NULL);
		return (ret);
	}
	return (ft_strdup(str));
}
