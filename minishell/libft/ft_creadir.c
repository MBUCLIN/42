/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creadir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:08:34 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/31 14:09:58 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_creadir(char *path, char *name)
{
	char		*ret;

	if ((ret = ft_strjoin(path, "/")) == NULL)
		return (NULL);
	if ((ret = ft_strjoinfree(ret, name)) == NULL)
		return (NULL);
	return (ret);
}
