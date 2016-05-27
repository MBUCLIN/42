/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:07:15 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/27 16:16:16 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

char		*read_command(char *line, int n)
{
	if ((line = get_linecommand(line)) == NULL)
		return (NULL);
	n = ft_strnchr(line, '\"');
	if (n == 0)
		return (line);
	else if (n < 0)
	{
		free(line);
		return (NULL);
	}
	else if (n % 2 == 0)
		return (line);
	return (read_command(line, n));
}
