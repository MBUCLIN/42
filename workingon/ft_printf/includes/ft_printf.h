/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:53:34 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/24 17:22:34 by mbuclin          ###   ########.fr       */
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

int					ft_string_len(char *s);
int					ft_getadj(char *info);
int					ft_isconvc(int c);
int					ft_isconvi(int c);
int					ft_isconv(int c);
int					ft_isflag(int c);
int					ft_iswidth(const char *fmt, int i);
int					ft_ispreci(int i);
int					ft_islm(char *str);
int					ft_chkcv(const char *fmt, int i);
int					ft_getpreci(char *info);
int					ft_getwidth(char *info);
int					ft_get_lm(char *conv);
int					ft_get_nbits(int wint);
int					ft_get_noct(int n);
char				*ft_getmask(int n);
char				*ft_getoct(int wint, char *mask);
char				*ft_convoct(char *bits, int olen);
char				*ft_apply_widtchar(char *info, char *s, int adj);
char				*ft_apply_wchar(char *info, int adj, va_list ap);
char				*ft_apply_wint(char *info, int adj, va_list ap);
char				*ft_apply_convp(char *info, int adj, va_list ap);
char				*ft_apply_pandw(int adj, char *info, char *conv);
char				*ft_apply_flagsi(char *info, char *conv);
char				*ft_apply_integc(char *info, int lm, int c, va_list ap);
char				*ft_apply_charc(char *info, int adj, va_list ap);
char				*ft_apply_conv(char *info, va_list ap, int lm);
int					ft_printf(const char *format, ...);

#endif
