#include "push_swap.h"

static int
	is_ascending_order(int x, int y)
{
	if (x < y)
		return (1);
	return (0);
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

static int
	rotate_a_until_min(t_dlist *a)
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

static int
	push_max(t_stacks *stacks)
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

static int
	push_min(t_stacks *stacks)
{
	size_t	min_node_idx;
	int		ret;

	min_node_idx = cdl_get_min_node_idx(&stacks->a);
	if (min_node_idx == 0)
		return (0);
	if (!rotate_a_until_min(&stacks->a))
		return (0);
	if (!cdl_is_sorted(stacks->a.head, stacks->a.head->next, is_ascending_order))
	{
		ret = ft_pb(&stacks->a, &stacks->b, stacks->a.head->next->n);
		return (ret);
	}
	return (SORTED);
}

static int
	check_circular_sorted(t_dlist *dlist, t_dnode *skip)
{
	t_dnode	*start;
	t_dnode	*crnt;
	t_dnode *next;

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

void
	ft_sort_6(t_stacks *stacks)
{
	size_t	size;
	int		ret;

	ret = 1;
	size = cdl_size(&stacks->a);
	if (4 < size && !cdl_is_sorted(stacks->a.head, stacks->a.head->next, is_ascending_order)
		&& cdl_is_sorted(stacks->a.head, stacks->a.head->next->next, is_ascending_order))
		ft_ss(&stacks->a, NULL);
	if (4 < size && !check_circular_sorted(&stacks->a, NULL)
		&& check_circular_sorted(&stacks->a, cdl_get_max_node(&stacks->a)))
	{
		ret = push_max(stacks);
		if (!ret)
			ft_exit_failure(stacks);
		ret = rotate_a_until_min(&stacks->a);
	}
	else
	{
		while (ret != SORTED && ret)
		{
			size = cdl_size(&stacks->a);
			if (size <= 3)
				break ;
			if (size == 4)
				ft_sort_4(&stacks->a);
			ret = push_min(stacks);
			if (!ret)
				ft_exit_failure(stacks);
		}
		if (ret != SORTED && ret)
			ft_sort_3(&stacks->a);
	}
	while (ret && stacks->b.head->next != stacks->b.head)
		ret = ft_pa(&stacks->a, &stacks->b, stacks->b.head->next->n);
	if (!ret || !rotate_a_until_min(&stacks->a))
		ft_exit_failure(stacks);
}
