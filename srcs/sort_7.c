/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:10:04 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/21 16:36:30 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	rotate_a(t_stacks *stacks, int end_id)
{
	size_t	idx;
	size_t	size;

	if (end_id == -1)
		return ;
	size = cdl_size(&stacks->a);
	while (1)
	{
		idx = cdl_get_idx_by_id(&stacks->a, end_id);
		if (idx == 0)
			return ;
		else if (idx == size)
			return ;
		else if (idx == 1)
		{
			ft_rr(&stacks->a, NULL);
			return ;
		}
		ft_rotate(stacks, idx + 1, 'a');
	}
}

static int
	pa_and_rotate_b(t_stacks *stacks, int l, int r, int pivot_id)
{
	size_t	size;
	t_dnode	*ptr;
	int		not_targets;
	t_bool	not_targets_flag;

	size = 0;
	if (l <= r)
		size = r - l + 1;
	if (size <= 4)
	{
		ft_sort_6_b(stacks);
		return (SORTED);
	}
	not_targets = r - pivot_id + 1;
	not_targets_flag = FALSE;
	if (not_targets == 0)
		not_targets_flag = TRUE;
	ptr = stacks->b.head->next;
	while (ptr != stacks->b.head
		&& ((not_targets_flag == FALSE && not_targets) || not_targets_flag == TRUE))
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
			ft_ra_or_rr(stacks, l);
		}
		else if (pivot_id <= ptr->id)
		{
			if (!ft_pa(&stacks->a, &stacks->b))
				return (0);
			not_targets--;
		}
		else if (stacks->b.head->prev->id == l)
			ft_rrr(NULL, &stacks->b);
		else
			ft_rotate_b_until_find_id_in_range(&stacks->b, pivot_id, l, r);
		ptr = stacks->b.head->next;
	}
	if (not_targets_flag == FALSE && not_targets == 0 && cdl_size(&stacks->b))
	{
		int	min_id;
		int	max_id;
		int	next_l;
		int	ret;

		min_id = cdl_get_min_node(&stacks->b)->id;
		max_id = cdl_get_max_node(&stacks->b)->id;
		ret = 1;
		while (ret != SORTED && ret)
		{
			next_l = (min_id + max_id) / 2;
			ret = pa_and_rotate_b(stacks, min_id, max_id, next_l);
			if (ret != SORTED)
				ft_pb_and_rotate_a(stacks, &next_l, max_id, FALSE);
			else if (!ret){}
			if (ret != SORTED)
				rotate_a(stacks, next_l - 1);
			else
				rotate_a(stacks, max_id);
			min_id = next_l;
		}
	}
	return (1);
}

static void	sort_b(t_stacks *stacks, int l, int r);

static void
	sort_a(t_stacks *stacks, int l, int r, t_bool is_first)
{
	int	ret;

	if (l == r)
		return ;
	if (cdl_is_asc_order_range(&stacks->a, l, r))
		return ;
	ret = ft_pb_and_rotate_a(stacks, &l, r, is_first);
	if (!ret)
		return (ft_exit_failure(stacks));
	sort_b(stacks, l, r);
}

static void
	sort_b(t_stacks *stacks, int l, int r)
{
	int	pivot_id;
	int	ret;

	if (cdl_is_empty(&stacks->b))
		return ;
	rotate_a(stacks, l - 1);
	pivot_id = (l + r) / 2;
	ret = pa_and_rotate_b(stacks, l, r, pivot_id);
	if (!ret)
		return (ft_exit_failure(stacks));
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
	ft_rotate_a_until_min(stacks);
}
