#include "../includes/ft_ls.h"

int		main(int argc, char **argv)
{
	int		opt;
	t_all	*all;

	opt = init_option(argc - 1, argv + 1);
	ft_printf("%X : option\n", opt);
	if (opt == -1)
		return (0);
	if (!(arg = recup_args(argc - 1, argv + 1)))
		return (0);
	print_file(arg);
	arg = del_only_file(arg);
	if (arg && (option & OPT_MR))
	{
		if (!(arg = recursive(arg, option)))
			return (0);
	}
	else if (arg)
		arg = read_dir_arg(arg, opt);
	del_all(arg);
	return (1);
}
