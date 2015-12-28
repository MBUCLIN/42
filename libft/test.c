#include <libft.h>
#include <string.h>

#define    SIZE 10000

int main(void)
{

	char *s1;
	char *s2;

	s1 = (char *)malloc(SIZE);
	s2 = (char *)malloc(SIZE);
	memset(s1, 'a', SIZE);
	ft_memcpy(s2, s1, SIZE);
	if (memcmp(s1, s2, SIZE) == 0)
		write(1, ".", 1);
	else
		write(1, "X", 1);
	return (0);
}
