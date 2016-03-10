#include "../includes/ft_printf.h"

static int		after_conv(const char *fmt, int pos)
{
	while (fmt[++pos])
		if (ft_isconv(fmt[pos]))
			return (pos + 1);
	return (pos);
}

static char		*extract_info(const char *fmt)
{
	int		i;

	i = 0;
	while (fmt[++i])
	{
		if (ft_isconv(fmt[i]))
			return (ft_strsub(fmt, 0, i + 1));
	}
	return (NULL);
}

static t_printf		*get_opt(const char *fmt, t_printf *print, va_list ap)
{
	char		*ext;
	t_printf	*conv;

	conv = NULL;
	ext = NULL;
	if (!(ext = extract_info(fmt)))
		return (NULL);
	if (!(conv = ft_getconv(ext, ap)))
		return (NULL);
	if (!(print = ft_strjoinprintf(print, conv->opt, conv->size)))
		return (NULL);
	free(conv);
	return (print);
}

static t_printf		*big_loop(const char *fmt, t_printf *p, va_list ap, int i)
{
	int			st;
	int			len;
	char		*sub;

	st = 0;
	len = ft_strlen(fmt);
	while (fmt[++i])
		if (fmt[i] == '%' && ft_checkconv(fmt, i))
		{
			if (!(p = ft_strjoinprintf(p,\
				ft_strsub(fmt, st, i - st), i - st)))
				return (NULL);
			if (!(p = get_opt((fmt + i), p, ap)))
				return (NULL);
			st = after_conv(fmt, i);
			i = st;
		}
	if (!(sub = ft_strsub(fmt, st, len - st)))
		return (NULL);
	if (!(p = ft_strjoinprintf(p, sub, len - st)))
		return (NULL);
	return (p);
}

int				ft_printf(const char *format, ...)
{
	t_printf	*print;
	va_list		ap;
	int			size;

	if (!(print = (t_printf *)malloc(sizeof(t_printf) * 1)))
		return (0);
	print->opt = NULL;
	print->size = 0;
	va_start(ap, format);
	if (!(print = big_loop(format, print, ap, -1)))
		return (0);
	write(1, print->opt, print->size);
	size = print->size;
	free(print->opt);
	free(print);
	return (size);
}
