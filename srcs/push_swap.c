#include "push_swap.h"

int
	main(int argc, char **argv)
{
	if (ft_is_valid_args(argc, argv) == false)
	{
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	// TODO: 重複
	ft_putendl_fd("hello", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
