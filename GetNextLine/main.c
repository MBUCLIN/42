#include "Get_Next_Line/get_next_line.h"

int		main(int ac, char **av)
{
	char		*line;
	int			gob;
	int			fd;

	gob = 1;
	line = NULL;
	if (ac < 2)
	{
		while ((gob = get_next_line(0, &line)) > 0)
		{
			ft_putendl(line);
			free(line);
			line = NULL;
		}
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	while ((gob = get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);
		free(line);
		line = NULL;
	}
	close(fd);
	if ((fd = open(av[2], O_RDONLY)) == -1)
		return (0);
	while ((gob = get_next_line(fd, &line)) > 0)
	{
		ft_putendl(line);
		free(line);
		line = NULL;
	}
	close (fd);
	return (1);
}
