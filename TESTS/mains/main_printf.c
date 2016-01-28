/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:33:28 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/28 13:34:51 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_putendl("---TEST INT\n\n");
	ft_putstr("d : sys = ");
	printf("j ai %d ans\n", 20);
	ft_putstr("d : my  = ");
	ft_printf("j ai %.5#d ans\n", 20);
	ft_putstr("i : sys = ");
	printf("j ai %#i ans\n", 20);
	ft_putstr("i : my  = ");
	ft_printf("j ai %#i ans\n", 20);
	ft_putstr("o : sys = ");
	printf("0o%5#o\n", 20);
	ft_putstr("o : my  = ");
	ft_printf("0o%#o\n", 20);
	ft_putstr("u : sys = ");
	printf("j ai %#u ans\n", 20);
	ft_putstr("u : my  = ");
	ft_printf("j ai %#u ans\n", 20);
	ft_putstr("x : sys = ");
	printf("0x%#x\n", 20);
	ft_putstr("x : my  = ");
	ft_printf("0x%#x\n", 20);
	ft_putstr("X : sys = ");
	printf("0X%#X\n", 20);
	ft_putstr("X : my  = ");
	ft_printf("0X%#X\n", 20);

	ft_putendl("\n\n\n---TEST LONG---\n\n");
	ft_putstr("D : sys = ");
	printf("j ai %#D ans\n", 20);
	ft_putstr("D : my  = ");
	ft_printf("j ai %#D ans\n", 20);
	ft_putstr("O : sys = ");
	printf("0O%#O\n", 20);
	ft_putstr("O : my  = ");
	ft_printf("0O%#O\n", 20);
	ft_putstr("U : sys = ");
	printf("J ai %#U ans\n", 20);
	ft_putstr("U : my  = ");
	ft_printf("j ai %#U ans\n", 20);
	return (0);
}
