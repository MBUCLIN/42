#include "libft.h"

char		*ft_strmidadd(char *tocut, char *toadd, int i)
{
	char	*p1;
	char	*p2;

	p1 = NULL;
	p2 = NULL;
	if (tocut == NULL)
		return (NULL);
	else if (toadd == NULL)
		return (tocut);
	else if (i == 0)
		return (ft_strjoindfree(toadd, tocut));
	if (!(p1 = ft_strsub(tocut, 0, i)))
		return (NULL);
	if (!(p2 = ft_strsub(tocut, i, ft_strlen(tocut) - i)))
		return (NULL);
	if (!(toadd = ft_strjoindfree(p1, toadd)))
		return (NULL);
	return (ft_strjoindfree(toadd, p2));
}
