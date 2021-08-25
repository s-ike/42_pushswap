/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_7_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:44:35 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/25 23:24:24 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	init(size_t *size, int *not_targets, int *id, int pivot_id)
{
	*size = 0;
	if (id[L] <= id[R])
		*size = id[R] - id[L] + 1;
	*not_targets = 0;
	if (pivot_id <= id[R])
		*not_targets = id[R] - pivot_id + 1;
}

static int
	split_b(t_pushswap *ps)
{
	int	min_id;
	int	max_id;
	int	pivot_id;
	int	ret;

	min_id = cdl_get_min_node(&ps->stacks.b)->id;
	max_id = cdl_get_max_node(&ps->stacks.b)->id;
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
	int		not_targets;
	t_bool	not_targets_flag;
	int		id[LR];

	id[L] = l;
	id[R] = r;
	init(&size, &not_targets, id, pivot_id);
	if (size < SORTSIZE)
	{
		ft_sort_6_b(ps);
		return (SORTED);
	}
	not_targets_flag = FALSE;
	if (not_targets == 0)
		not_targets_flag = TRUE;
	id[R] = pivot_id;
	ft_pa_and_rotate_b_loop(ps, &not_targets, not_targets_flag, id);
	if (not_targets_flag == FALSE && not_targets == 0
		&& cdl_size(&ps->stacks.b))
	{
		if (!split_b(ps))
			return (0);
	}
	return (1);
}
