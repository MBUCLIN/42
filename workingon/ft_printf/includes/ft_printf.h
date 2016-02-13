/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:53:34 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/10 16:15:54 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <inttypes.h>

typedef struct		s_info
{
	int				flag;
	int				width;
	int				preci;
	int				lm;
}					t_info;

int					ft_getadj(char *info);
char				*ft_apply_pandw(int adj, char *info, char *conv);
char				*ft_apply_flagsi(char *info, char *conv);
char				*ft_apply_integc(int lm, int c, va_list ap);
int					ft_isconvc(int c);
int					ft_isconvi(int c);
int					ft_isconv(int c);
int					ft_isflag(int c);
int					ft_iswidth(const char *fmt, int i);
int					ft_ispreci(int i);
int					ft_islm(char *str);
int					ft_chkcv(const char *fmt, int i);
int					ft_get_lm(char *conv);
int					ft_printf(const char *format, ...);

#endif
