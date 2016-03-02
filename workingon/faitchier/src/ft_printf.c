#include "../includes/ft_printf.h"

static int		after_conv(const char *fmt, int pos)
{
	while (fmt[++pos])
		if (ft_isconv(fmt[pos]))
			return (pos);
	return (pos);
}

static char		*extcnv(const char *fmt, int start)
{
	int		i;

	i = start;
	while (fmt[++i])
	{
		if (ft_isconv(fmt[i]))
			return (ft_strsub(fmt, start, i - start + 1));
	}
	return (NULL);
}

static int		get_conv(char **conv, char *info, va_list ap)
{
	int		size;
	int		lm;
	int		c;

	if (info == NULL)
		return (0);
	size = 0;
	c = ft_strlen(info) -1;
	lm = ft_get_lm(info);
	if (ft_isconvc(info[c]))
		return (ft_apply_conv(conv, info, lm, ap));
	size = ft_apply_integ(conv, info, ap, lm);
	size = ft_apply_flagsi(conv, info);
	return (size);
}

static int		get_opt(const char *fmt, char **opt, va_list ap, int i)
{
	int			st;
	int			len;
	int			size;
	char		*conv;

	st = -1;
	len = ft_strlen(fmt);
	size = 0;
	conv = NULL;
	while (fmt[++i])
		if (fmt[i] == '%' && ft_checkconv(fmt, i))
		{
			st += 1;
			*opt = ft_strjoinprintf(*opt, ft_strsub(fmt, st, i - st), size);
			size = size + ft_getlen((fmt + st));
			st = after_conv(fmt, i);
			size = size + get_conv(&conv, extcnv(fmt, i), ap);
			*opt = ft_strjoinprintf(*opt, conv, size);
			if (*opt == NULL)
				return (-1);
			i = st;
		}
	st += 1;
	if (!(*opt = ft_strjoinprintf(*opt, ft_strsub(fmt, st, len - st), size)))
		return (-1);
	return (size + ft_strlen((fmt + st)));
}

int				ft_printf(const char *format, ...)
{
	char		*opt;
	va_list		ap;
	int			size;

	opt = NULL;
	va_start(ap, format);
	size = get_opt(format, &opt, ap, -1);
	if (size == -1)
		return (0);
	ft_print_opt(opt, size);
	ft_memset(opt, 0, size);
	free(opt);
	return (size);
}
