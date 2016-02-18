#include "../libft/includes/libft.h"

int		main(int argc, char **argv)
{
	int fd1;
	int	fd2;
	int gp;
	int gmp;
	char *linep;
	char *linemp;
	int n;
	int	i;

	 i = 1;
	if (argc != 3)
		return (0);
	n = 1;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	linep = NULL;
	linemp = NULL;
	while ((gp = get_next_line(fd1, &linep)) && (gmp = get_next_line(fd2, &linemp)))
	{
		if (gp == -1|| gmp == -1)
		{
			ft_putendl(" error GNL ...");
			return (0);
		}
		if (linep == NULL && linemp == NULL)
			return (0);
		else if (linep == NULL)
		{
			free(linemp);
			return (0);
		}
		else if (linemp == NULL)
		{
			free(linep);
			return (0);
		}
		if (ft_strcmp(linep, linemp))
		{
			ft_putstr("\033[31m");
			ft_putstr(linep);
			ft_putendl("	: Line printf");
			ft_putstr(linemp);
			ft_putendl("	: Line your printf");
			ft_putnbr(i);
			ft_putendl("");
			ft_putstr("\033[0m");
			free(linep);
			free(linemp);
			linep = NULL;
			linemp = NULL;
		}
		else
		{
			ft_putstr("\033[32m");
			ft_putnbr(i);
			ft_putstr(" = ");
			ft_putendl("OK\033[0m");
		}
		free(linep);
		linep = NULL;
		free(linemp);
		linemp = NULL;
		i++;
	}
	return (0);
}
