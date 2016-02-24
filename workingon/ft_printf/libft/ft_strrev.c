#include "includes/libft.h"

void		ft_strrev(char	*s)
{
	int		j;
	int		i;
	char	c;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}
