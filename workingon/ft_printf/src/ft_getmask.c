#include "../includes/ft_printf.h"

char		*ft_getmask(int n)
{
	if (n <= 7)
		return (ft_strdup("0xxxxxxx"));
	else if (n <= 11)
		return (ft_strdup("110xxxxx10xxxxxx"));
	else if (n <= 16)
		return (ft_strdup("110xxxxx10xxxxxx10xxxxxx"));
	return (ft_strdup("110xxxxx10xxxxxx10xxxxxx10xxxxxx"));
}
