#include "push_swap.h"

static void
	make_stack_a(t_dlist *a, int argc, char **argv)
{
	int	is_sorted;
	int	prev_n;
	int	crnt_n;
	int	i;

	is_sorted = true;
	prev_n = INT32_MIN;
	i = 1;
	while (i < argc)
	{
		crnt_n = ft_atoi(argv[i++]);
		if (is_sorted && crnt_n < prev_n)
			is_sorted = false;
		if (!ft_append_stack_while_check_dup(a, crnt_n))
		{
			ft_terminate_stack(a);
			ft_putendl_fd(MSG_ERR, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		prev_n = crnt_n;
	}
	if (is_sorted)
	{
		ft_terminate_stack(a);
		exit(EXIT_SUCCESS);
	}
}
#include <stdio.h>
int
	main(int argc, char **argv)
{
	t_dlist	a;

	if (ft_is_valid_args(argc, argv) == false || !ft_init_stack(&a))
	{
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	make_stack_a(&a, argc, argv);
	ft_sort(&a);
	cdl_print_dlist(&a);
	ft_terminate_stack(&a);
	// system("leaks push_swap");
	exit(EXIT_SUCCESS);
}
