#include "push_swap.h"

static int
	cnt_less_than_id_in_range(t_dlist *dlist, int l, int r, int pivot)
{
	t_dnode	*ptr;
	int		cnt;

	ptr = dlist->head->next;
	cnt = 0;
	while (ptr != dlist->head)
	{
		if (l <= ptr->id && ptr->id <= r && ptr->id < pivot)
			cnt++;
		ptr = ptr->next;
	}
	return (cnt);
}

static int
	cnt_more_than_id_in_range(t_dlist *dlist, int l, int r, int pivot)
{
	t_dnode	*ptr;
	int		cnt;

	ptr = dlist->head->next;
	cnt = 0;
	while (ptr != dlist->head)
	{
		if (l <= ptr->id && ptr->id <= r && ptr->id > pivot)
			cnt++;
		ptr = ptr->next;
	}
	return (cnt);
}

static int
	push_to_b_and_rotate(t_stacks *stacks, int l, int r, int pivot_id)
{
	int		ret;
	int		targets;
	size_t	size;
	t_dnode	*ptr;

	ret = 1;
	size = 0;
	if (l <= r)
		size = r - l + 1;
	ptr = stacks->a.head->next;
	targets = cnt_less_than_id_in_range(&stacks->a, l, r, pivot_id);
	while (ret && targets && ptr != stacks->a.head)
	{
		if (size <= 2
			&& ((ptr->id == l && ptr->next->id == r) || (ptr->id == r && ptr->next->id == l)))
		{
			ft_sort_2(&stacks->a);
			return (SORTED);
		}
		else if (size > 2 && l <= ptr->id && ptr->id <= r && ptr->id < pivot_id)
		{
			// もしtargets==1&&ptr->id == rの場合最大値なのでpbしてもすぐpaされるのでする必要がない
			// ただし単にスキップしてしまって良いか
			ret = ft_pb(&stacks->a, &stacks->b);
			targets--;
		}
		else
			ft_rotate_a_less_than_p_in_range(&stacks->a, pivot_id, l, r);
		ptr = stacks->a.head->next;
	}
	return (ret);
}

static int
	push_to_a(t_stacks *stacks, int l, int r, int pivot_id)
{
	int		ret;
	int		targets;
	size_t	size;
	t_dnode	*ptr;

	ret = r;
	size = 0;
	if (l <= r)
		size = r - l + 1;
	// if (size <= 5)にできるか
	if (size <= 3)
	{
		ft_sort_3_b(&stacks->b);
		pivot_id = -1;
		ret = r + 1;
	}
	ptr = stacks->b.head->next;
	targets = cnt_more_than_id_in_range(&stacks->b, l, r, pivot_id);
	while (targets && ptr != stacks->b.head)
	{
		if (ptr->id > pivot_id)
		{
			if (ft_pa(&stacks->a, &stacks->b))
				targets--;
			else
				return (-1);
		}
		else
			ft_rotate_b_more_than_p_in_range(&stacks->b, pivot_id, l, r);
		ptr = stacks->b.head->next;
	}
	return (ret);
}

static void
	rotate_a(t_dlist *a, int end_id)
{
	size_t	idx;
	size_t	size;

	if (end_id == -1)
		return ;
	size = cdl_size(a);
	while (1)
	{
		idx = cdl_get_idx_by_id(a, end_id);
		if (idx == 0)
			return ;
		else if (idx == size)
			return ;
		else if (idx == 1)
		{
			ft_rr(a, NULL);
			return ;
		}
		else
			ft_rotate_a(a, idx + 1);
	}
}

static void
	sort_7(t_stacks *stacks, int l, int r)
{
	size_t	size;
	int		pivot_id;
	int		ret;

	size = cdl_size(&stacks->a);
	// if (size == 2)
	// 	ft_sort_3(&stacks->a);
	if (l == 0 && (int)(size - 1) == r)
		pivot_id = size / 2;
	else if (l <= r)
		pivot_id = (r - l + 1) / 2 + l;
	else
		pivot_id = l;
	// pivot_idよりも大きいidをbへpush
	// この範囲が揃っていなければpush_b
	ret = 1;
	if (!((size_t)r + 1 == size
		&& cdl_is_range_sorted_asc_order(&stacks->a, l, r)))
		ret = push_to_b_and_rotate(stacks, l, r, pivot_id);
	else
		ft_rotate_a_until_min(&stacks->a);
	if (!ret)
	{
		//
	}
	pivot_id--;
	while (r != -1 && !cdl_is_empty(&stacks->b))
	{
		int	bl;

		bl = l;
		rotate_a(&stacks->a, l - 1);
		r = pivot_id;
		pivot_id = (r - bl + 1) / 2 + bl;
		// printf("%d, %d, %d\n", bl, r, pivot_id);
		r = push_to_a(stacks, bl, r, pivot_id);
		bl = r;
	}
	if (r == -1)
	{
		//
	}
	if (cdl_is_sorted(stacks->a.head, stacks->a.head->next, ft_is_ascending_order))
		return ;
	if (r == l)
		r++;
	sort_7(stacks, r, cdl_size(&stacks->a) - 1);
}

void
	ft_sort_7(t_stacks *stacks)
{
	if (cdl_is_sorted(stacks->a.head, stacks->a.head->next, ft_is_ascending_order))
		return ;
	sort_7(stacks, 0, cdl_size(&stacks->a) - 1);
}
