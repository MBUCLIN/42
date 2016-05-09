/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:23:44 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/17 14:50:07 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <inttypes.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_printf
{
	int			size;
	char		*opt;
}				t_printf;

int				ft_strlen(const char *str);
int				ft_get_ncar(int *wchar);
int				ft_carchr(int c, char *s);
void			ft_putnbr(int nbr);
void			ft_memset(void *p, int c, int len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strsub(const char *tosub, int sta, int size);
char			*ft_strdup(const char *s);
char			*ft_strsubfree(char *tosub, int sta, int size);
char			*ft_strmidadd(char *tocut, char *toadd, int i);
t_printf		*ft_strjoinprintf(t_printf *print, char *s2, int len2);
char			*ft_strjoindfree(char *s1, char *s2);
char			*ft_strdupfree(char *s);
char			*ft_strdupprintf(const char *src, int size);
void			ft_strrev(char *s);
char			*ft_sitoabase(size_t nbr, const char *base);
char			*ft_sitoa(ssize_t nbr);
char			*ft_itoa(int nbr);
char			*ft_itoabase(unsigned int nbr, const char *base);
int				ft_atoibasefree(char *nbr_b, char *base);
int				ft_atoi(char *str);
int				ft_string_len(char *s);
char			*ft_convoct(char *bits, int olen);
int				ft_isunsigned(int c);
int				ft_isdigit(int c);
int				ft_isconvi(int c);
int				ft_isconvc(int c);
int				ft_isconv(int c);
int				ft_isgoodcar(int c);
char			*ft_getoct(int wint, char *mask);
int				ft_get_nbits(int wint);
int				ft_get_noct(int n);
char			*ft_getmask(int n);
int				ft_getwidth(char *info);
int				ft_getpreci(char *info);
int				ft_get_lm(char *info);
int				ft_getlen(const char *fmt);
int				ft_getadj(char *info);
int				ft_checkconv(const char *fmt, int i);
t_printf		*ft_apply_widtchar(char *info, t_printf *conv, int adj);
char			*ft_apply_pandw(int adj, char *info, char *conv);
t_printf		*ft_apply_int(t_printf *conv, char *info, va_list ap, int lm);
t_printf		*ft_apply_flagsi(char *info, t_printf *conv);
t_printf		*ft_apply_number(char *info, va_list ap, int lm);
t_printf		*ft_apply_wchar(char *info, int adj, va_list ap);
t_printf		*ft_apply_wint(char *info, int adj, va_list ap);
t_printf		*ft_apply_convp(char *info, int adj, va_list ap);
t_printf		*ft_apply_charc(char *info, int adj, va_list ap);
t_printf		*ft_apply_conv(char *info, int lm, va_list ap);
t_printf		*ft_getconv(char *info, va_list ap);
int				ft_printf(const char *format, ...);

#endif
