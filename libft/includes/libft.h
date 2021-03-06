/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:11:41 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/21 14:56:08 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define FT_ABS(n) ((n) < 0 ? -(n) : (n))
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				h;
	int				w;
	int				bpp;
	int				slb;
	int				endian;
	int				z;
	int				x;
	int				y;
}					t_img;

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t len);
void				*ft_deltabstr(char **del, int pos);

void				ft_exit(char **args);
void				ft_memdel(void **ap);
void				ft_handle(int sig);
void				ft_strdel(char **as);
void				ft_bzero(void *s, size_t len);
void				ft_tabdel(void **todel);
void				ft_strclr(char *s);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl(char const *str);
void				ft_putendl_fd(int fd, char const *str);
void				ft_putnbr(int nbr);
void				ft_putnbr_fd(int nbr, int fd);
void				ft_putnbrbase(int nbr, char *base);
void				ft_putlst(t_list *head);
void				ft_swap(int *n1, int *n2);
void				ft_puttab(char **tab);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_imgcpy(t_img **dest, t_img *src);
void				ft_fill_data(t_img **img, int x, int y, int color);
void				ft_delstrcontent(void *content, size_t size);
void				ft_swaptabstr(char ***tab, int st, int len);

size_t				ft_strlen(char const *str);
int					ft_skpblk(char *str);
int					ft_lstlen(t_list *head);
int					ft_tabstrlen(char **tabstr);
int					ft_tabstrsrch(char *srch, char **tab);
int					ft_nlen(int n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isstrdigit(char *str);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isstrascii(char *str);
int					ft_isprint(int c);
int					ft_isblank(int c);
int					ft_strisblank(char *str);
int					ft_isoption(int c, char *option);
int					ft_islexisort(const char *s1, const char *s2);
int					ft_isrevlexisort(char *s1, char *s2);
int					ft_isempty(char *str);
int					ft_chrnotoption(char *chr, char *option);
int					ft_atoi(char *str);
int					ft_atoibase(char *nbr_b, char *base);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strnchr(char *str, int c);
int					ft_writechar(int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
ssize_t				ft_satoi(char *str);

char				*ft_itoa(int nbr);
char				*ft_sitoa(ssize_t nbr);
char				*ft_itoabase(unsigned int nbr, char *base);
char				*ft_sitoabase(size_t nbr, char *base);
char				*ft_strnew(size_t size);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcrpl(char *str, int search, int replace);
char				*ft_strdup(const char *s);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsubfree(char *str, int n, int len);
char				*ft_substrc(char *str, int c);
char				*ft_strmap(char *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char *s1, char const *s2);
char				*ft_strjoindfree(char *s1, char *s2);
char				*ft_strmidadd(char *tocut, char *toadd, int i);
char				*ft_strtrim(char const *s);
char				*ft_strncadd(char *str, int n, int c);
char				*ft_creadir(char *path, char *name);
char				*ft_srchenv(char *varname, char **env);
char				*ft_treatquote(char *str);
char				*ft_rpcstr(char *rpc, char *str, int st, int end);
char				**ft_chgvalue(char *name, char *nvalue, char **tab);
char				**ft_strsplit(char const *s, char c);
char				**ft_tabstrdup(char **tab);
char				**ft_lsttotabstrfree(t_list *head);
char				**ft_addstrtotab(char **tab, char *str);
char				**ft_deltabswapstr(char **env, char *del, int len);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstindex(t_list *head, int index);
t_list				*ft_artol(char **array);

#endif
