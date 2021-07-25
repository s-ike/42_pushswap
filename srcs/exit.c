#include "push_swap.h"

void
	ft_exit_failure(t_stacks *stacks)
{
	ft_terminate_stacks(stacks);
	ft_putendl_fd(MSG_ERR, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void
	ft_exit_success(t_stacks *stacks)
{
	ft_terminate_stacks(stacks);
	exit(EXIT_SUCCESS);
}

void
	ft_exit_success_with_leaks(t_stacks *stacks)
{
	ft_terminate_stacks(stacks);
	system("leaks push_swap");
	exit(EXIT_SUCCESS);
}
