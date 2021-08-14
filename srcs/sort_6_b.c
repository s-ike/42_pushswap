/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 01:02:15 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/15 01:02:34 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	push_max(t_stacks *stacks)
{
	size_t	max_node_idx;
	int		ret;

	max_node_idx = cdl_get_max_node_idx(&stacks->b);
	if (max_node_idx == 0)
		return (0);
	if (max_node_idx == 2
		&& stacks->b.head->next->next->id - 1 == stacks->b.head->next->id)
	{
		ft_ss(NULL, &stacks->b);
		max_node_idx = cdl_get_max_node_idx(&stacks->b);
	}
	while (max_node_idx != 1)
	{
		ft_rotate(&stacks->b, max_node_idx, 'b');
		max_node_idx = cdl_get_max_node_idx(&stacks->b);
		if (max_node_idx == 0)
			return (0);
	}
	ret = ft_pa(&stacks->a, &stacks->b);
	return (ret);
}

static int
	push_to_a_and_rotate(t_stacks *stacks, size_t size)
{
	int	ret;

	ret = 1;
	size = cdl_size(&stacks->b);
	while (4 <= size)
	{
		ret = push_max(stacks);
		if (!ret)
			return (ret);
		size = cdl_size(&stacks->b);
	}
	if (ret)
		ret = ft_sort_3_b_and_pa(stacks);
	return (ret);
}

void
	ft_sort_6_b(t_stacks *stacks)
{
	size_t	size;
	int		ret;

	ret = 1;
	size = cdl_size(&stacks->a);
	ret = push_to_a_and_rotate(stacks, size);
	if (!ret)
		ft_exit_failure(stacks);
}
