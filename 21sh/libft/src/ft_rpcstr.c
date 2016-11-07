/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rpcstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 15:22:36 by mbuclin           #+#    #+#             */
/*   Updated: 2016/07/13 16:40:14 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_rpcstr(char *rpc, char *str, int st, int end)
{
	char	*f_part;
	char	*e_part;
	char	*ret;

	f_part = NULL;
	e_part = NULL;
	if (st != 0)
		if ((f_part = ft_strsub(str, 0, st)) == NULL)
			return (NULL);
	if ((size_t)end != ft_strlen(str) - 1)
		if ((e_part = ft_strsub(str, end, ft_strlen(str) - end)) == NULL)
			return (NULL);
	if ((ret = ft_strjoindfree(f_part, rpc)) == NULL)
		return (NULL);
	return (ft_strjoindfree(ret, e_part));
}
