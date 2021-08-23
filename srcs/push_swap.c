/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:09:34 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/23 21:45:57 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_pushswap	ps;
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
		ft_exit_failure(&stacks);
	}
	if (!make_stack_a(&stacks, &sort_list))
		ft_exit_failure(&stacks);
	ps.stacks = &stacks;
	ps.ans = NULL;
	ft_sort(&ps);
	t_list	*ans_ptr;
	ans_ptr = ps.ans;
	while (ans_ptr)
	{
		ft_putendl_fd(ans_ptr->content, STDOUT_FILENO);
		ans_ptr = ans_ptr->next;
	}
	if (0)
		test_print(ps.stacks);
	ft_exit_success(&stacks);
	// TODO:
	// ft_lstclear(&ps.ans, free);
}
