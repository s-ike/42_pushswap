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

static void
	rotate_a(t_dlist *a, size_t target_node_idx)
{
	size_t	proximity;
	size_t	size;

	size = cdl_size(a);
	proximity = size / 2;
	if (proximity < (size + 1) / 2)
		proximity = (size + 1) / 2;
	if (proximity < target_node_idx)
		ft_rrr(a, NULL);
	else
		ft_rr(a, NULL);
}

int
	ft_rotate_a_until_min(t_dlist *a)
{
	size_t	min_node_idx;

	min_node_idx = cdl_get_min_node_idx(a);
	if (min_node_idx == 0)
		return (0);
	while (min_node_idx != 1)
	{
		rotate_a(a, min_node_idx);
		min_node_idx = cdl_get_min_node_idx(a);
		if (min_node_idx == 0)
			return (0);
	}
	return (1);
}

int
	ft_push_max(t_stacks *stacks)
{
	size_t	max_node_idx;
	int		ret;

	max_node_idx = cdl_get_max_node_idx(&stacks->a);
	if (max_node_idx == 0)
		return (0);
	while (max_node_idx != 1)
	{
		rotate_a(&stacks->a, max_node_idx);
		max_node_idx = cdl_get_max_node_idx(&stacks->a);
		if (max_node_idx == 0)
			return (0);
	}
	ret = ft_pb(&stacks->a, &stacks->b, stacks->a.head->next->n);
	return (ret);
}

int
	ft_push_min(t_stacks *stacks)
{
	size_t	min_node_idx;
	int		ret;

	min_node_idx = cdl_get_min_node_idx(&stacks->a);
	if (min_node_idx == 0)
		return (0);
	if (!ft_rotate_a_until_min(&stacks->a))
		return (0);
	if (!cdl_is_sorted(
			stacks->a.head, stacks->a.head->next, ft_is_ascending_order))
	{
		ret = ft_pb(&stacks->a, &stacks->b, stacks->a.head->next->n);
		return (ret);
	}
	return (SORTED);
}
