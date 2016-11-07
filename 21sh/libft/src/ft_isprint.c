/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:48:39 by mbuclin           #+#    #+#             */
/*   Updated: 2015/11/26 16:48:42 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isprint(int c)
{
	if (ft_isalpha(c) != 0)
		return (ft_isalpha(c));
	else if (ft_isdigit(c) != 0)
		return (ft_isdigit(c));
	else if (c < 32 || c > 126)
		return (0);
	return (16);
}
