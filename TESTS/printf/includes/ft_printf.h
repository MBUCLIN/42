/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:39:12 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/28 15:40:32 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>

typedef struct			s_printf
{
	char				*conv;
	int					flag;
//	int					fieldcar;
//	int					preci;
//	int					width;
//	int					lor;
	int					c;
}						t_printf;

int						ft_is_int(int c);
int						ft_is_long(int c);
int						ft_is_char(int c);
int						ft_is_wconv(int c);
int						ft_is_conv(int c);
int						ft_get_flag(char *inf);
char					*ft_apply_flag(int flag, int c);
char					*ft_apply_int(int c, va_list ap);
char					*ft_apply_long(int c, va_list ap);
char					*ft_apply_conv(int c, va_list ap);
char					*ft_conv(t_printf *inf, va_list ap);
char					*ft_treat_conv(const char *fmt, int i, va_list ap);
int						ft_printf(const char *format, ...);
#endif
