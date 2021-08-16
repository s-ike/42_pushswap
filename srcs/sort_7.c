#include "push_swap.h"
/*
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
}*/

// static int
// 	can_rotate_b(t_dlist *b, int l, int r)
// {
// 	int	pivot_id;

// 	if (cdl_is_empty(b) || cdl_size(b) == 1)
// 		return (0);
// 	pivot_id = (l + r) / 2;
// 	if (b->head->next->id < pivot_id && pivot_id <= b->head->next->next->id)
// 		return (1);
// 	return (0);
// }

static int
	pb_and_rotate_a(t_stacks *stacks, int *l, int r, t_bool is_first)
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
		if (is_first == FALSE)
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
		}
		// if (*l <= ptr->id && ptr->id <= r && can_rotate_b(&stacks->b, *l, r))
		// 	ft_rr(NULL, &stacks->b);
		// else if (*l <= ptr->id && ptr->id <= r)
		// {
		// 	ret = ft_pb(&stacks->a, &stacks->b);
		// 	targets--;
		// }
		// else if (targets && can_rotate_b(&stacks->b, *l, r))
		// 	ft_rr(&stacks->a, &stacks->b);
		// else if (targets)
		// 	ft_rr(&stacks->a, NULL);
		if (*l <= ptr->id && ptr->id <= r)
		{
			ret = ft_pb(&stacks->a, &stacks->b);
			targets--;
			// pbする最後の要素の場合はbの先頭にあると良いので行わない
			if (2 <= cdl_size(&stacks->b)
				&& (stacks->b.head->next->id == *l
					|| (stacks->b.head->next->id == *l + 1 && cdl_get_min_node(&stacks->b)->id != *l)))
				ft_rr(NULL, &stacks->b);
		}
		else if (targets)
			ft_rr(&stacks->a, NULL);
		ptr = stacks->a.head->next;
	}
	return (ret);
}

static void
	ra_or_rr(t_stacks *stacks, int l)
{
	if (stacks->b.head->next->id == l)
		return (ft_rr(&stacks->a, NULL));
	else if (stacks->b.head->prev->id == l)
	{
		ft_rr(&stacks->a, NULL);
		return (ft_rrr(NULL, &stacks->b));
	}
	else if (1 < cdl_size(&stacks->b))
		return (ft_rr(&stacks->a, &stacks->b));
}

static int
	pa_and_rotate_b(t_stacks *stacks, int l, int r, int pivot_id)
{
	size_t	size;
	t_dnode	*ptr;
	// t_bool	is_last;

	size = 0;
	if (l <= r)
		size = r - l + 1;
	ptr = stacks->b.head->next;
	if (size <= 4)
	{
		// bの先頭が最小値であればpaしてrrかrb
		ft_sort_6_b(stacks);
		while (size--)
			ft_rr(&stacks->a, NULL);
		return (SORTED);
	}
	// is_last = FALSE;
	while (ptr != stacks->b.head)
	{
		// if (ptr->id + 1 == ptr->next->id && pivot_id <= ptr->next->id)
		// 	ft_ss(NULL, &stacks->b);

		// else if (ptr->id + 1 == stacks->b.head->prev->id
		// 	&& pivot_id <= stacks->b.head->prev->id)
		// 	ft_rrr(NULL, &stacks->b);
		if (ptr->id < pivot_id && ptr->id == l)
		{

			// if (ptr->id + 1 == pivot_id)
			// 	is_last = TRUE;

			if (!ft_pa(&stacks->a, &stacks->b))
				return (0);
			l++;
			ra_or_rr(stacks, l);
		}
		else if (pivot_id <= ptr->id)
		{
			if (!ft_pa(&stacks->a, &stacks->b))
				return (0);
		}
		else if (stacks->b.head->prev->id == l)
			ft_rrr(NULL, &stacks->b);
		else
			ft_rotate_b_until_find_id_in_range(&stacks->b, pivot_id, l, r);
		ptr = stacks->b.head->next;
	}
	return (1);
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
	sort_a(t_stacks *stacks, int l, int r, t_bool is_first)
{
	int	ret;

	if (l == r)
		return ;
	ret = 1;
	if (cdl_is_sorted_asc_in_range(&stacks->a, l, r))
		return ;
	// check_range_a_is_sorted(&stacks->a, &l, r);
	if (l != r)
		ret = pb_and_rotate_a(stacks, &l, r, is_first);
	if (!ret)
	{
	}
	sort_b(stacks, l, r);
}

static void
	sa(t_dlist *a, int r, int *p)
{
	t_dnode	*ptr;

	ptr = a->head->next;
	while (ptr != a->head && ptr->next != a->head && ptr->id <= r
		&& ptr->next->id == a->head->prev->id + 1
		&& ptr->id == ptr->next->id + 1)
	{
		ft_ss(a, NULL);
		ft_rr(a, NULL);
		ft_rr(a, NULL);
		(*p) += 2;
		ptr = a->head->next;
	}
}

static void
	sort_b(t_stacks *stacks, int l, int r)
{
	int	pivot_id;
	int	ret;

	if (cdl_is_empty(&stacks->b))
		return ;
	rotate_a(&stacks->a, l - 1);
	pivot_id = (l + r) / 2; // 0-7の8要素で3になる
	ret = pa_and_rotate_b(stacks, l, r, pivot_id);
	if (!ret)
	{
	}
	sa(&stacks->a, r, &pivot_id);
	sort_b(stacks, l, pivot_id - 1);
	if (l == r || ret == SORTED)
		return ;
	sort_a(stacks, pivot_id, r, FALSE);
}

static void
	sort_7(t_stacks *stacks, int l, int r)
{
	int	pivot_id;

	if (l == r)
		return ;
	pivot_id = (l + r) / 2;
	sort_a(stacks, l, pivot_id, TRUE);
	sort_a(stacks, pivot_id, r, FALSE);
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
