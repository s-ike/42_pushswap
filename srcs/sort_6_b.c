#include "push_swap.h"

// static void
// 	swap_firt_value(t_stacks *stacks, size_t size)
// {
// 	if (4 < size
// 		&& !cdl_is_sorted(
// 			stacks->a.head, stacks->a.head->next, ft_is_ascending_order)
// 		&& cdl_is_sorted(
// 			stacks->a.head, stacks->a.head->next->next, ft_is_ascending_order))
// 		ft_ss(&stacks->a, NULL);
// }

static void
	check_sb(t_dlist *b, size_t size)
{
	if (size < 4)
		return ;
	if (b->head->next->next->id == (int)(size - 1)
		&& b->head->next->next->id - 1 == b->head->next->id)
		ft_ss(NULL, b);
}

int
	push_max(t_stacks *stacks)
{
	size_t	max_node_idx;
	int		ret;

	max_node_idx = cdl_get_max_node_idx(&stacks->b);
	if (max_node_idx == 0)
		return (0);
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
	while (size)
	{
		if (4 <= size)
		{
			check_sb(&stacks->b, size);
			ret = push_max(stacks);
		}
		else
			break ;
		if (!ret)
			return (ret);
		size = cdl_size(&stacks->b);
	}
	if (ret)
		ft_sort_3_b(&stacks->b);
	return (ret);
}

void
	ft_sort_6_b(t_stacks *stacks)
{
	size_t	size;
	int		ret;

	ret = 1;
	size = cdl_size(&stacks->a);
	// swap_firt_value(stacks, size);
	ret = push_to_a_and_rotate(stacks, size);
	while (ret && !cdl_is_empty(&stacks->b))
		ret = ft_pa(&stacks->a, &stacks->b);
	if (!ret)
		ft_exit_failure(stacks);
}
