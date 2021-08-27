/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:09:56 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/27 02:32:39 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	ft_check_circular_sorted(t_dlist *dlist, t_dnode *skip)
{
	t_dnode	*start;
	t_dnode	*crnt;
	t_dnode	*next;

	start = cdl_get_min_node(dlist);
	crnt = start->next;
	next = crnt->next;
	while (next != start)
	{
		while (next == dlist->head || next == skip)
			next = next->next;
		if (next->n < crnt->n)
			return (0);
		crnt = next;
		next = crnt->next;
	}
	return (1);
}

int
	ft_rotate_a_until_min(t_pushswap *ps)
{
	t_dlist	*a;
	size_t	min_node_idx;

	a = &ps->stacks.a;
	min_node_idx = cdl_get_min_node_idx(a);
	if (min_node_idx == 0)
		return (0);
	while (min_node_idx != 1)
	{
		ft_rotate(ps, min_node_idx, 'a');
		min_node_idx = cdl_get_min_node_idx(a);
		if (min_node_idx == 0)
			return (0);
	}
	return (1);
}

int
	ft_pb_max(t_pushswap *ps)
{
	size_t	max_node_idx;
	t_dlist	*a;
	t_dlist	*b;

	a = &ps->stacks.a;
	b = &ps->stacks.b;
	max_node_idx = cdl_get_max_node_idx(a);
	if (max_node_idx == 0)
		return (0);
	while (max_node_idx != 1)
	{
		ft_rotate(ps, max_node_idx, 'a');
		max_node_idx = cdl_get_max_node_idx(a);
		if (max_node_idx == 0)
			return (0);
	}
	ft_pb(a, b, ps, TRUE);
	return (1);
}

int
	ft_pb_min(t_pushswap *ps)
{
	t_dlist	*a;
	t_dlist	*b;

	a = &ps->stacks.a;
	b = &ps->stacks.b;
	if (!ft_rotate_a_until_min(ps))
		return (0);
	if (!cdl_is_sorted(a->head, a->head->next, ft_is_ascending_order))
	{
		ft_pb(a, b, ps, TRUE);
		return (1);
	}
	return (SORTED);
}
