/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:39:12 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/27 15:11:27 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/libft.h"
# include <stdarg.h>

int		ft_is_int(int c);
int		ft_is_long(int c);
int		ft_is_char(int c);
int		ft_is_wconv(int c);
int		ft_is_conv(int c);

char	*ft_apply_int(int c, va_list ap);
char	*ft_apply_conv(int c, va_list ap);

int		ft_get_nconv(const char *fmt);
char	*ft_conv(const char* fmt, char *opt, int i, va_list ap);

int		ft_printf(const char *format, ...);
#endif
