#include "../includes/ft_printf.h"

char		*ft_getoct(int wint, char *mask)
{
	int				len;
	unsigned int	mkfield;

	mkfield = 0x1;
	len = ft_strlen(mask);
	len -= 1;
	while (len >= 0)
	{
		if (mask[len] == 'x')
		{
			if (mkfield & wint)
				mask[len] = '1';
			else
				mask[len] = '0';
		mkfield <<= 1;
		}
		len--;
	}
	return (mask);
}
