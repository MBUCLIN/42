/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:33:21 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/27 14:40:59 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

char		*recreate_command(char *cmd)
{
	int		len;
	char	*newone;

	len = 0;
	if (cmd != NULL)
		len = ft_strlen(cmd);
	if ((newone = (char *)malloc(sizeof(char) * (len + BUF_SIZE + 1))) == NULL)
		return (NULL);
	ft_bzero(newone, len + BUF_SIZE + 1);
	newone = ft_strcpy(newone, cmd);
	return (newone);
}

char		*recreate_szchar(char *szchar)
{
	int		len;
	char	*newone;

	len = 0;
	if (szchar)
		len = ft_strlen(szchar);
	if ((newone = (char *)malloc(sizeof(char) * (len + BUF_SIZE + 1))) == NULL)
		return (NULL);
	ft_bzero(newone, len + BUF_SIZE + 1);
	newone = ft_strcpy(newone, szchar);
	return (newone);
}

