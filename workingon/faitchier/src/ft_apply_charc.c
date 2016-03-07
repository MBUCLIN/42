#include "../includes/ft_printf.h"

static t_printf		*joinprecileft(t_printf *conv, char *preci, int size)
{
	char	*join;
	int		dsize;

	join = NULL;
	dsize = conv->size + size;
	if (!(join = (char *)malloc(sizeof(char) * (dsize + 1))))
		return (NULL);
	ft_memcpy(join, preci, size);
	ft_memcpy((join + size), conv->opt, conv->size);
	join[dsize] = 0;
	free(preci);
	free(conv->opt);
	conv->opt = NULL;
	if (!(conv->opt = ft_strdupprintf(join, dsize)))
		return (NULL);
	free(join);
	conv->size = dsize;
	return (conv);
}

static t_printf		*apply_c(int adj, t_printf *conv, char *info)
{
	int		size;
	char	*preci;

	preci = NULL;
	size = ft_getpreci(info) - conv->size;
	if (size >= 1)
		if (!(preci = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
	if (size < 1)
		return (ft_apply_widtchar(info, conv, adj));
	preci[size] = 0;
	ft_memset(preci, ' ', size);
	if (!(conv = joinprecileft(conv, preci, size)))
		return (NULL);
	return (ft_apply_widtchar(info, conv, adj));
}

t_printf			*ft_apply_charc(char *info, int adj, va_list ap)
{
	char		c;
	t_printf	*conv;

	if (!(conv = (t_printf *)malloc(sizeof(t_printf) * 1)))
		return (NULL);
	if (info[ft_strlen(info) - 1] != '%')
	{
		c = (char)va_arg(ap, int);
		if (!(conv->opt = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		conv->opt[0] = c;
		conv->opt[1] = 0;
	}
	else
		if (!(conv->opt = ft_strdup("%")))
			return (NULL);
	conv->size = 1;
	return (apply_c(adj, conv, info));
}
