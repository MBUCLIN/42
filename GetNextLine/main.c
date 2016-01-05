#include "get_next_line.h"

int		main(int ac, char **av)
{
	char		*line;
	int			gob;
	int			fd;

	gob = 1;
	fd = 0;
	line = NULL;
	if (ac < 2)
	{
		while (gob == 1)
		{
			gob = get_next_line(0, &line);
			if (gob == -1)
			{
				ft_putendl("FUCKED ERROR");
				return (0);
			}
			ft_putendl(line);
			free(line);
			line = NULL;
		}
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	while (gob == 1)
	{
		gob = get_next_line(fd, &line);
		ft_putnbr(gob);
		ft_putendl("");
		if (gob == -1)
		{
			ft_putendl("FUCKED ERROR");
			return (0);
		}
		ft_putendl(line);
		free(line);
		line = NULL;
	}
	return (1);
}
