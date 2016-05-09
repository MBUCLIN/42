/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmask.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:20:29 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/17 14:40:44 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_getmask(int n)
{
	if (n <= 7)
		return (ft_strdup("0xxxxxxx"));
	else if (n <= 11)
		return (ft_strdup("110xxxxx10xxxxxx"));
	else if (n <= 16)
		return (ft_strdup("1110xxxx10xxxxxx10xxxxxx"));
	return (ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxx"));
}
