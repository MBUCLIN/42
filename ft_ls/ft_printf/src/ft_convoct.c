/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convoct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:19:48 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/17 14:40:27 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_convoct(char *bits, int olen)
{
	char	*oct;
	int		blen;

	blen = ft_strlen(bits);
	if (!(oct = (char *)malloc(sizeof(char) * (olen + 1))))
		return (NULL);
	oct[olen] = '\0';
	ft_memset(oct, ' ', olen);
	if (oct[0] != 0)
		oct[0] = ft_atoibasefree(ft_strdup((bits + (blen - 8))), "01");
	if (oct[1] != 0)
		oct[1] = ft_atoibasefree(ft_strsub(bits, blen - 16, 8), "01");
	if (oct[2] != 0)
		oct[2] = ft_atoibasefree(ft_strsub(bits, blen - 24, 8), "01");
	if (oct[3] != 0)
		oct[3] = ft_atoibasefree(ft_strsub(bits, 0, 8), "01");
	free(bits);
	ft_strrev(oct);
	return (oct);
}
