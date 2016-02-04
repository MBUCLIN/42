/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:53:34 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/03 16:30:30 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/libft.h"
# include <stdarg.h>

int					ft_isconvc(int c);
int					ft_isconvi(int c);
int					ft_isconv(int c);
int					ft_get_lm(char *conv);
int					ft_printf(const char *format, ...);

#endif
