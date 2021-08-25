#include "push_swap.h"

int
	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (!ft_is_valid_args(argc, argv) || !ft_init_stacks(&stacks))
	{
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_terminate_stacks(&stacks);
#ifdef LEAKS
	system("leaks checker");
#endif
	exit(EXIT_SUCCESS);
}
