#include "push_swap.h"

static int
	cnt_more_than_id_in_range(t_dlist *dlist, int l, int r, int pivot)
{
	t_dnode	*ptr;
	int		cnt;

	ptr = dlist->head->next;
	cnt = 0;
	while (ptr != dlist->head)
	{
		if (l <= ptr->id && ptr->id <= r && pivot <= ptr->id)
			cnt++;
		ptr = ptr->next;
	}
	return (cnt);
}

static int
	push_to_b_and_rotate(t_stacks *stacks, int *l, int r)
{
	int		ret;
	int		targets;
	t_dnode	*ptr;
	int		flag;

	ret = 1;
	targets = 0;
	if (*l <= r)
		targets = r - *l + 1;
	ptr = stacks->a.head->next;
	flag = 0;
	while (ret && targets && ptr != stacks->a.head)
	{
		if ((stacks->a.head->next->id == *l
				&& (stacks->a.head->prev->id == *l - 1 || !flag))
			|| (stacks->a.head->prev->id == *l
				&& (stacks->a.head->prev->prev->id == *l - 1 || !flag)))
		{
			(*l)++;
			targets--;
			flag = 1;
		}
		if (*l <= ptr->id && ptr->id <= r)
		{
			ret = ft_pb(&stacks->a, &stacks->b);
			targets--;
		}
		else if (targets)
			ft_rotate_a_in_range(&stacks->a, *l, r);
		ptr = stacks->a.head->next;
	}
	return (ret);
}

static int
	push_to_a_and_rotate(t_stacks *stacks, int l, int r, int pivot_id)
{
	int		targets;
	size_t	size;
	t_dnode	*ptr;
	int		ret;

	size = 0;
	if (l <= r)
		size = r - l + 1;
	ret = 1;
	ptr = stacks->b.head->next;
	targets = cnt_more_than_id_in_range(&stacks->b, l, r, pivot_id);
	if (size <= 6)
	{
		ft_sort_6_b(stacks);
		return (SORTED);
	}
	while (targets && ptr != stacks->b.head)
	{
		if (ptr->id + 1 == ptr->next->id && pivot_id <= ptr->next->id)
			ft_ss(NULL, &stacks->b);
		else if (ptr->id + 1 == stacks->b.head->prev->id
			&& pivot_id <= stacks->b.head->prev->id)
			ft_rrr(NULL, &stacks->b);
		if (ret == SORTED || pivot_id <= ptr->id)
		{
			if (ft_pa(&stacks->a, &stacks->b))
				targets--;
			else
				return (0);
		}
		else
			ft_rotate_b_until_find_id_or_more_in_range(
				&stacks->b, pivot_id, l, r);
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
			ft_rotate(a, idx + 1, 'a');
	}
}

// static void
// 	check_range_a_is_sorted(t_dlist *a, int *l, int r)
// {
// 	t_dnode	*start;
// 	t_dnode	*ptr;
// 	t_dnode	*prev;

// 	ptr = cdl_get_node_by_id(a, *l);
// 	if (!ptr)
// 		return ;
// 	start = ptr;
// 	prev = ptr;
// 	ptr = ptr->next;
// 	if (ptr == a->head)
// 		ptr = ptr->next;
// 	while (ptr != start)
// 	{
// 		if (r < ptr->id || prev->id + 1 != ptr->id)
// 			break ;
// 		(*l)++;
// 		prev = ptr;
// 		ptr = ptr->next;
// 		if (ptr == a->head)
// 			ptr = ptr->next;
// 	}
// }

static void	sort_b(t_stacks *stacks, int l, int r);

static void
	sort_a(t_stacks *stacks, int l, int r)
{
	int	ret;

	if (l == r)
		return ;
	ret = 1;
	if (cdl_is_sorted_asc_in_range(&stacks->a, l, r))
		return ;
	// check_range_a_is_sorted(&stacks->a, &l, r);
	if (l != r)
		ret = push_to_b_and_rotate(stacks, &l, r);
	if (!ret)
	{
	}
	sort_b(stacks, l, r);
}

static void
	sort_b(t_stacks *stacks, int l, int r)
{
	int	pivot_id;
	int	ret;

	if (cdl_is_empty(&stacks->b))
		return ;
	rotate_a(&stacks->a, l - 1);
	pivot_id = (l + r) / 2;
	ret = push_to_a_and_rotate(stacks, l, r, pivot_id);
	if (!ret)
	{
	}
	sort_b(stacks, l, pivot_id - 1);
	if (l == r || ret == SORTED)
		return ;
	sort_a(stacks, pivot_id, r);
}

static void
	sort_7(t_stacks *stacks, int l, int r)
{
	int	pivot_id;

	if (l == r)
		return ;
	pivot_id = (l + r) / 2;
	sort_a(stacks, l, pivot_id - 1);
	sort_a(stacks, pivot_id, r);
}

void
	ft_sort_7(t_stacks *stacks)
{
	if (cdl_is_sorted(
			stacks->a.head, stacks->a.head->next, ft_is_ascending_order))
		return ;
	sort_7(stacks, 0, cdl_size(&stacks->a) - 1);
	ft_rotate_a_until_min(&stacks->a);
}
