#include "push_swap.h"

static int
	make_stack_a(t_stacks *stacks, t_list **sort_list)
{
	t_list	*ptr;
	t_sort	*sort_info;

	ptr = *sort_list;
	while (ptr)
	{
		sort_info = ptr->content;
		if (!cdl_add_back_dlist(&stacks->a, sort_info->n, sort_info->id))
		{
			ft_lstclear(sort_list, free);
			return (0);
		}
		ptr = ptr->next;
	}
	ft_lstclear(sort_list, free);
	return (1);
}

#include <stdio.h>
int
	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_list		*sort_list;

	// char	*argv[] = {"./push_swap", "1", "5", "2", "4", "3", "6", "7"};
	// int		argc = sizeof(argv) / sizeof(argv[0]);

	if (!ft_is_valid_args(argc, argv) || !ft_init_stacks(&stacks))
	{
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ft_make_sort_list(&sort_list, argc, argv))
		ft_exit_failure(&stacks);
	// 重複チェックが効いていない、以下の7と18が重複している引数で検出せず
	// 7 20 11 5 0 1 19 18 2 7 17 18 3 9 4 16 12 8
	if (!ft_check_dup_n(&sort_list))
	{
		ft_lstclear(&sort_list, free);
		ft_exit_failure(&stacks);
	}
	if (!make_stack_a(&stacks, &sort_list))
		ft_exit_failure(&stacks);
	ft_sort(&stacks);
	// ft_putendl_fd("a", STDOUT_FILENO);
	// cdl_print_dlist(&stacks.a);
	// ft_putendl_fd("b", STDOUT_FILENO);
	// cdl_print_dlist(&stacks.b);
	if (0) // debug
		ft_exit_success_with_leaks(&stacks);
	ft_exit_success(&stacks);
}
