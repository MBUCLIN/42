/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:33:28 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/27 15:01:35 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("%d\n", 20);
	ft_printf("%d\n", 20);
	printf("%i\n", 20);
	ft_printf("%i\n, 20");
	printf("%o\n", 20);
	ft_printf("%o\n", 20);
	printf("%u\n", 20);
	ft_printf("%u\n", 20);
	printf("%x\n", 20);
	ft_printf("%x\n", 20);
	printf("%X\n", 20);
	ft_printf("%X\n", 20);
	return (0);
}
