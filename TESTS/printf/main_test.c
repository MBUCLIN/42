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
	ft_putstr("d : sys = ");
	printf("%d\n", 20);
	ft_putstr("d : my  = ");
	ft_printf("%d\n", 20);
	ft_putstr("i : sys = ");
	printf("%i\n", 20);
	ft_putstr("i : my  = ");
	ft_printf("%i\n", 20);
	ft_putstr("o : sys = ");
	printf("%o\n", 20);
	ft_putstr("o : my  = ");
	ft_printf("%o\n", 20);
	ft_putstr("u : sys = ");
	printf("%u\n", 20);
	ft_putstr("u : my  = ");
	ft_printf("%u\n", 20);
	ft_putstr("x : sys = ");
	printf("%x\n", 20);
	ft_putstr("x : my  = ");
	ft_printf("%x\n", 20);
	ft_putstr("X : sys = ");
	printf("%X\n", 20);
	ft_putstr("X : my  = ");
	ft_printf("%X\n", 20);
	return (0);
}
