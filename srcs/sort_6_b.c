/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 01:02:15 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/20 11:19:39 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	push_min(t_stacks *stacks)
{
	size_t	min_node_idx;
	int		ret;

	min_node_idx = cdl_get_min_node_idx(&stacks->b);
	if (min_node_idx == 0)
		return (0);
	if (min_node_idx == 2
		&& stacks->b.head->next->next->id + 1 == stacks->b.head->next->id)
	{
		ft_ss(NULL, &stacks->b);
		min_node_idx = cdl_get_min_node_idx(&stacks->b);
	}
	while (min_node_idx != 1)
	{
		ft_rotate(stacks, min_node_idx, 'b');
		min_node_idx = cdl_get_min_node_idx(&stacks->b);
		if (min_node_idx == 0)
			return (0);
	}
	ret = ft_pa(&stacks->a, &stacks->b);
	return (ret);
}

static int
	pa_and_rotate(t_stacks *stacks, size_t size)
{
	int	ret;

	ret = 1;
	size = cdl_size(&stacks->b);
	while (size)
	{
		ret = push_min(stacks);
		if (!ret)
			return (ret);
		size = cdl_size(&stacks->b);
		if (size)
			ft_ra_or_rr(stacks, cdl_get_min_node(&stacks->b)->id);
		else
			ft_ra_or_rr(stacks, 0);
	}
	return (ret);
}

void
	ft_sort_6_b(t_stacks *stacks)
{
	size_t	size;
	int		ret;

	ret = 1;
	size = cdl_size(&stacks->a);
	ret = pa_and_rotate(stacks, size);
	if (!ret)
		ft_exit_failure(stacks);
}
