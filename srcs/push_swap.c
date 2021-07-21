#include "push_swap.h"

int
	main(int argc, char **argv)
{
	t_dlist	a;
	int		i;

	if (ft_is_valid_args(argc, argv) == false)
	{
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ft_init_stack(&a))
	{
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (i < argc)
	{
		if (!ft_append_stack(&a, ft_atoi(argv[i++])))
		{
			ft_putendl_fd(MSG_ERR, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	// TODO: 重複
	cdl_print_dlist(&a);
	ft_terminate_stack(&a);
	// system("leaks push_swap");
	exit(EXIT_SUCCESS);
}
