#include "push_swap.h"

static int
	is_ascending_order(int x, int y)
{
	if (x < y)
		return (1);
	return (0);
}

static int
	rotate_until_min(t_dlist *blist, const char name)
{
	size_t	min_node_idx;
	size_t	proximity;
	size_t	size;

	min_node_idx = cdl_get_min_node_idx(blist);
	if (min_node_idx == 0)
		return (0);
	while (min_node_idx != 1)
	{
		size = cdl_size(blist);
		proximity = size / 2;
		if (proximity < (size + 1) / 2)
			proximity = (size + 1) / 2;
		if (proximity < min_node_idx)
		{
			if (name == 'a')
				ft_rrr(blist, NULL);
			else
				ft_rrr(NULL, blist);
		}
		else
		{
			if (name == 'a')
				ft_rr(blist, NULL);
			else
				ft_rr(NULL, blist);
		}
		min_node_idx = cdl_get_min_node_idx(blist);
		if (min_node_idx == 0)
			return (0);
	}
	return (1);
}

static int
	push_max(t_dlist *a, t_dlist *b)
{
	size_t	max_node_idx;
	int		ret;

	max_node_idx = cdl_get_max_node_idx(a);
	if (max_node_idx == 0)
		return (0);
	while (max_node_idx != 1)
	{
		size_t	proximity;
		size_t	size;

		size = cdl_size(a);
		proximity = size / 2;
		if (proximity < (size + 1) / 2)
			proximity = (size + 1) / 2;
		if (proximity < max_node_idx)
			ft_rrr(a, NULL);
		else
			ft_rr(a, NULL);
		max_node_idx = cdl_get_max_node_idx(a);
		if (max_node_idx == 0)
			return (0);
	}
	ret = ft_pb(a, b, a->head->next->n);
	return (ret);
}

static int
	push_min(t_dlist *a, t_dlist *b)
{
	size_t	min_node_idx;
	int		ret;

	min_node_idx = cdl_get_min_node_idx(a);
	if (min_node_idx == 0)
		return (0);
	if (!rotate_until_min(a, 'a'))
		return (0);
	if (!cdl_is_sorted(a->head, a->head->next, is_ascending_order))
	{
		ret = ft_pb(a, b, a->head->next->n);
		return (ret);
	}
	return (-1);
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
	ft_sort_6(t_dlist *a)
{
	t_dlist	b;
	size_t	size;
	int		ret;

	if (!ft_init_stack(&b))
	{
		ft_terminate_stack(a);
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ret = 1;
	size = cdl_size(a);
	if (4 < size && !cdl_is_sorted(a->head, a->head->next, is_ascending_order)
		&& cdl_is_sorted(a->head, a->head->next->next, is_ascending_order))
		ft_ss(a, NULL);
	if (4 < size && !check_circular_sorted(a, NULL)
		&& check_circular_sorted(a, cdl_get_max_node(a))) // 最大値以外が循環ソートされている
	{
		// puts("special");
		ret = push_max(a, &b);
		if (!ret)
		{
			ft_terminate_stack(a);
			ft_terminate_stack(&b);
			ft_putendl_fd(MSG_ERR, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		ret = rotate_until_min(a, 'a');
	}
	else
	{	// 最適化処理できないとき
		while (0 < ret)
		{
			size = cdl_size(a);
			if (size <= 3)
				break ;
			if (size == 4)
				ft_sort_4(a);
			ret = push_min(a, &b);
			if (!ret)
			{
				ft_terminate_stack(a);
				ft_terminate_stack(&b);
				ft_putendl_fd(MSG_ERR, STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
		}
		if (0 < ret)
			ft_sort_3(a);
	}
	while (ret && b.head->next != b.head)
		ret = ft_pa(a, &b, b.head->next->n);
	if (!ret || !rotate_until_min(a, 'a'))
	{
		ft_terminate_stack(a);
		ft_terminate_stack(&b);
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_terminate_stack(&b);
}
