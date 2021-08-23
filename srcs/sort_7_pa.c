/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_7_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:44:35 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/23 01:26:23 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	cnt_rotate_b(t_dnode **ptr, int *start_id, size_t *cnt, int target_id)
{
	int	flag[LR];

	flag[L] = 0;
	flag[R] = 0;
	while (ptr[L]->id != start_id[R] && ptr[R]->id != start_id[L])
	{
		if (ptr[L]->id != start_id[R] && ptr[L]->id != target_id)
		{
			ptr[L] = ptr[L]->next;
			cnt[L]++;
		}
		else
			flag[L] = 1;
		if (ptr[R]->id != start_id[L] && ptr[R]->id != target_id)
		{
			ptr[R] = ptr[R]->prev;
			cnt[R]++;
		}
		else
			flag[R] = 1;
		if ((flag[L] && flag[R]) || cnt[L] < cnt[R])
			break ;
	}
}

static char
	*rotate_b(t_dlist *b, int target_id)
{
	t_dnode	*ptr[LR];
	int		start_id[LR];
	size_t	cnt[LR];

	ptr[L] = b->head->next;
	ptr[R] = b->head->prev;
	start_id[L] = ptr[L]->id;
	start_id[R] = ptr[R]->id;
	cnt[L] = 0;
	cnt[R] = 0;
	cnt_rotate_b(ptr, start_id, cnt, target_id);
	if (cnt[L] < cnt[R])
		return (OP_RB);
	else if (cnt[R] < cnt[L] / 2)
		return (OP_RRB);
	else
		return (OP_RB);
}

static int
	pa_and_rotate_a(t_pushswap *ps, int *l)
{
	t_dlist	*a;
	t_dlist	*b;

	a = &ps->stacks->a;
	b = &ps->stacks->b;
	if (!ft_pa(a, b, ps))
		return (0);
	(*l)++;
	if (b->head->next->id == *l)
		ft_rr(a, NULL, ps);
	else if (!ft_strcmp(rotate_b(b, *l), OP_RB))
		ft_rr(a, b, ps);
	else
		ft_rr(a, NULL, ps);
	return (1);
}

static int
	split_b(t_pushswap *ps)
{
	int	min_id;
	int	max_id;
	int	pivot_id;
	int	ret;

	min_id = cdl_get_min_node(&ps->stacks->b)->id;
	max_id = cdl_get_max_node(&ps->stacks->b)->id;
	ret = 1;
	while (ret != SORTED && ret)
	{
		pivot_id = (min_id + max_id) / 2;
		ret = ft_pa_and_rotate_b(ps, min_id, max_id, pivot_id);
		if (ret != SORTED)
			ft_pb_and_rotate_a(ps, &pivot_id, max_id, FALSE);
		else if (!ret)
			return (0);
		if (ret != SORTED)
			ft_rotate_a(ps, pivot_id - 1);
		else
			ft_rotate_a(ps, max_id);
		min_id = pivot_id;
	}
	return (1);
}

int
	ft_pa_and_rotate_b(t_pushswap *ps, int l, int r, int pivot_id)
{
	size_t	size;
	t_dnode	*ptr;
	int		not_targets;
	t_bool	not_targets_flag;

	size = 0;
	if (l <= r)
		size = r - l + 1;
	if (size < SORTSIZE)
	{
		ft_sort_6_b(ps);
		return (SORTED);
	}
	not_targets = r - pivot_id + 1;
	not_targets_flag = FALSE;
	if (not_targets == 0)
		not_targets_flag = TRUE;
	ptr = ps->stacks->b.head->next;
	while (ptr != ps->stacks->b.head
		&& ((not_targets_flag == FALSE && not_targets)
			|| not_targets_flag == TRUE))
	{
		if (ptr->id < pivot_id && ptr->id == l)
		{
			if (!pa_and_rotate_a(ps, &l))
				return (0);
		}
		else if (pivot_id <= ptr->id)
		{
			if (!ft_pa(&ps->stacks->a, &ps->stacks->b, ps))
				return (0);
			not_targets--;
		}
		else if (ps->stacks->b.head->prev->id == l)
			ft_rrr(NULL, &ps->stacks->b, ps);
		else
			ft_rotate_by_op(ps, rotate_b(&ps->stacks->b, l));
		ptr = ps->stacks->b.head->next;
	}
	if (not_targets_flag == FALSE && not_targets == 0 && cdl_size(&ps->stacks->b))
		if (!split_b(ps))
			return (0);
	return (1);
}
