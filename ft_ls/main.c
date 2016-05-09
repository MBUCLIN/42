#include "includes/ft_ls.h"

int		main(int argc, char **argv)
{
	int		opt;
	t_all	*arg;

	opt = init_option(argc - 1, argv + 1);
	if (opt == -1)
		return (0);
	if (!(arg = recup_args(argc - 1, argv + 1, opt)))
		return (0);
	print_file(arg, opt);
	arg = del_only_file(arg);
	if (arg && (opt & OPT_MR))
	{
		del_all(arg);
//		if (!(arg = recursive(arg, opt)))
//			return (0);
	}
	else if (arg)
	{
		ft_putendl("");
		arg = read_dir_arg(arg, opt);
	}
	del_all(arg);
	return (1);
}