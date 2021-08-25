/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 01:02:15 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/25 02:33:08 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	pa_min(t_pushswap *ps)
{
	size_t	min_node_idx;
	t_dlist	*b;

	b = &ps->stacks.b;
	min_node_idx = cdl_get_min_node_idx(b);
	if (min_node_idx == 0)
		return (0);
	if (min_node_idx == 2
		&& b->head->next->next->id + 1 == b->head->next->id)
	{
		ft_ss(NULL, b, ps);
		min_node_idx = cdl_get_min_node_idx(b);
	}
	while (min_node_idx != 1)
	{
		ft_rotate(ps, min_node_idx, 'b');
		min_node_idx = cdl_get_min_node_idx(b);
		if (min_node_idx == 0)
			return (0);
	}
	ft_pa(&ps->stacks.a, b, ps);
	return (1);
}

static int
	pa_and_rotate(t_pushswap *ps, size_t size)
{
	int		ret;
	t_dlist	*b;

	b = &ps->stacks.b;
	size = cdl_size(b);
	ret = 1;
	while (size)
	{
		if (size <= 3)
		{
			ft_sort_3_b_and_pa(ps);
			return (1);
		}
		ret = pa_min(ps);
		if (!ret)
			return (ret);
		size = cdl_size(b);
		if (size)
			ft_ra_or_rr(ps, cdl_get_min_node(b)->id);
		else
			ft_ra_or_rr(ps, 0);
	}
	return (ret);
}

void
	ft_sort_6_b(t_pushswap *ps)
{
	int		ret;
	size_t	size;

	size = cdl_size(&ps->stacks.a);
	ret = pa_and_rotate(ps, size);
	if (!ret)
		ft_exit_failure(ps);
}
