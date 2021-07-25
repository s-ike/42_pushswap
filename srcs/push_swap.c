#include "push_swap.h"

static void
	make_stack_a(t_stacks *stacks, int argc, char **argv)
{
	int	prev_n;
	int	crnt_n;
	int	i;

	prev_n = INT32_MIN;
	i = 1;
	while (i < argc)
	{
		crnt_n = ft_atoi(argv[i++]);
		if (!ft_append_stack_while_check_dup(&stacks->a, crnt_n))
			ft_exit_failure(stacks);
		prev_n = crnt_n;
	}
}

int
	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (ft_is_valid_args(argc, argv) == false || !ft_init_stacks(&stacks))
	{
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	make_stack_a(&stacks, argc, argv);
	ft_sort(&stacks);
	// cdl_print_dlist(&stacks.a);
	if (0) // debug
		ft_exit_success_with_leaks(&stacks);
	ft_exit_success(&stacks);
}
