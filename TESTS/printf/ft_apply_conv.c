#include "ft_printf.h"

char	*ft_apply_conv(int c, va_list ap)
{
	char	*conv;

	conv = NULL;
	if (ft_is_int(c))
		if (!(conv = ft_apply_int(c, ap)))
			return (NULL);
	if (ft_is_long(c))
		if (!(conv = ft_apply_long(c, ap)))
			return (NULL);
	if (ft_is_char(c))
		if (!(conv = ft_apply_char(c, ap)))
			return (NULL);
	if (ft_is_wconv(c))
		if (!(conv = ft_apply_wconv(c, ap)))
			return (NULL);
	if (conv)
		return (conv);
	return (NULL);
}
