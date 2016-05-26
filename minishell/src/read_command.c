/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:07:15 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/26 17:45:56 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

char		*read_command(char *line, int n)
{
	char		*afterpart;

	afterpart = NULL;
	if (line)
	{
		if (get_next_line(0, &afterpart) <= 0)
		{
			free(line);
			return (NULL);
		}
		if ((line = ft_strjoinfree(line, "\n")) == NULL)
			return (NULL);
		if ((line = ft_strjoindfree(line, afterpart)) == NULL)
			return (NULL);
	}
	else if (line == NULL)
		if (get_next_line(0, &line) <= 0)
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
