#include "../includes/ft_printf.h"

char	*ft_apply_flag(int flag, int c)
{
	if (flag == '#')
	{
		if (c == 'o')
			return (ft_strdup("0"));
		else if (c == 'x')
			return (ft_strdup("0x"));
		else if (c == 'X')
			return (ft_strdup("0X"));
	}
	return (NULL);
}
