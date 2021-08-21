/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_7_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:44:35 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/22 02:32:07 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	pa_and_rotate_a(t_stacks *stacks, int *l)
{
	if (!ft_pa(&stacks->a, &stacks->b))
		return (0);
	(*l)++;
	// このrr判定と、ft_rotate_b_until_find_id_in_rangeの判定が違う（rr,rrbが起きる）
	ft_ra_or_rr(stacks, *l);
	return (1);
}

static int
	split_b(t_stacks *stacks)
{
	int	min_id;
	int	max_id;
	int	pivot_id;
	int	ret;

	min_id = cdl_get_min_node(&stacks->b)->id;
	max_id = cdl_get_max_node(&stacks->b)->id;
	ret = 1;
	while (ret != SORTED && ret)
	{
		pivot_id = (min_id + max_id) / 2;
		ret = ft_pa_and_rotate_b(stacks, min_id, max_id, pivot_id);
		if (ret != SORTED)
			ft_pb_and_rotate_a(stacks, &pivot_id, max_id, FALSE);
		else if (!ret)
			return (0);
		if (ret != SORTED)
			ft_rotate_a(stacks, pivot_id - 1);
		else
			ft_rotate_a(stacks, max_id);
		min_id = pivot_id;
	}
	return (1);
}

int
	ft_pa_and_rotate_b(t_stacks *stacks, int l, int r, int pivot_id)
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
		ft_sort_6_b(stacks);
		return (SORTED);
	}
	not_targets = r - pivot_id + 1;
	not_targets_flag = FALSE;
	if (not_targets == 0)
		not_targets_flag = TRUE;
	ptr = stacks->b.head->next;
	while (ptr != stacks->b.head
		&& ((not_targets_flag == FALSE && not_targets)
			|| not_targets_flag == TRUE))
	{
		if (ptr->id < pivot_id && ptr->id == l)
		{
			if (!pa_and_rotate_a(stacks, &l))
				return (0);
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
		if (!split_b(stacks))
			return (0);
	return (1);
}
