#include "push_swap.h"

static void
	test_print(t_stacks *stacks)
{
	ft_putendl_fd("a", STDOUT_FILENO);
	cdl_print_dlist(&stacks->a);
	ft_putendl_fd("b", STDOUT_FILENO);
	cdl_print_dlist(&stacks->b);
}

int
	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_list		*sort_list;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (!ft_is_valid_args(argc, argv) || !ft_init_stacks(&stacks))
	{
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ft_make_sort_list(&sort_list, argc, argv))
	{
		ft_lstclear(&sort_list, free);
		ft_terminate_stacks(&stacks);
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ft_make_stack_a(&stacks, &sort_list))
	{
		ft_terminate_stacks(&stacks);
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	char	*line;
	int		ret;

	while (1)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (0 <= ret)
		{
			if (line)
				free(line);
		}
		if (ret <= 0)
			break ;
	}
	if (0)
		test_print(&stacks);

	ft_terminate_stacks(&stacks);
#ifdef LEAKS
	system("leaks checker");
#endif
	exit(EXIT_SUCCESS);
}
