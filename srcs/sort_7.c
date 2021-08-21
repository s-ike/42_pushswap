/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:10:04 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/21 22:15:38 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_rotate_a(t_stacks *stacks, int end_id)
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
	ft_rotate_a(stacks, l - 1);
	pivot_id = (l + r) / 2;
	ret = ft_pa_and_rotate_b(stacks, l, r, pivot_id);
	if (!ret)
		return (ft_exit_failure(stacks));
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
