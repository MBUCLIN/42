#include "../includes/ft_printf.h"

t_printf		*ft_getconv(char *info, va_list ap)
{
	int			lm;
	int			c;
	t_printf	*conv;

	if (!(conv = (t_printf *)malloc(sizeof(t_printf) * 1)))
		return (NULL);
	conv->opt = NULL;
	if (info == NULL)
		return (NULL);
	c = ft_strlen(info) - 1;
	lm = ft_get_lm(info);
	if (ft_isconvc(info[c]))
		return (ft_apply_conv(info, lm, ap));
	if (!(conv = ft_apply_number(info, ap, lm)))
		return (NULL);
	if (!(conv = ft_apply_flagsi(info, conv)))
		return (NULL);
	return (conv);
}
