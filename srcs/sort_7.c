#include "push_swap.h"

static int
	get_targets(t_dlist *dlist, int l, int r, int pivot)
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
	targets = get_targets(&stacks->a, l, r, pivot_id);
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
			ret = ft_pb(&stacks->a, &stacks->b);
			targets--;
		}
		else
			ft_rotate_a_less_than_p_in_range(&stacks->a, pivot_id, l, r);
		if (!ret)
			return (ret);
		ptr = stacks->a.head->next;
	}
	return (ret);
}

static int
	push_to_a(t_stacks *stacks, int l, int r, int pivot_id)
{
	int		ret;
	size_t	size;
	t_dnode	*ptr;
	t_dnode	*tmp;

	ret = 1;
	size = 0;
	if (l <= r)
		size = r - l + 1;
	// if (size <= 5)にできるか
	if (size <= 3)
	{
		ft_sort_3_b(&stacks->b);
		pivot_id = -1; // このとき戻った先でpivotの値をr+1にしたい、どこまでソートしたかをretに入れて返す？
	}
	ptr = stacks->b.head->next;
	while (ret && size-- && ptr != stacks->b.head)
	{
		tmp = ptr->next; // rr固定なので
		if (ptr->id > pivot_id)
			ret = ft_pa(&stacks->a, &stacks->b);
		else
			ft_rr(NULL, &stacks->b);
		if (!ret)
			return (ret);
		ptr = tmp;
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
	pivot_id--;
	while (ret && ret != SORTED && !cdl_is_empty(&stacks->b))
	{
		int	bl;

		bl = l;
		rotate_a(&stacks->a, l - 1);
		r = pivot_id;
		pivot_id = (r - bl + 1) / 2 + bl;
		// printf("%d, %d, %d\n", bl, r, pivot_id);
		ret = push_to_a(stacks, bl, r, pivot_id);
		bl = r;
	}
	if (!ret)
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
