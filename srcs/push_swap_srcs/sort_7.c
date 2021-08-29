/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:10:04 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/29 22:53:38 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_rotate_a(t_pushswap *ps, int end_id)
{
	t_dlist	*a;
	size_t	idx;
	size_t	size;

	a = &ps->stacks.a;
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
			ft_rr(a, NULL, ps, TRUE);
			return ;
		}
		ft_rotate(ps, idx + 1, 'a');
	}
}

static void	sort_b(t_pushswap *ps, int l, int r);

static void
	sort_a(t_pushswap *ps, int l, int r, t_bool is_first)
{
	if (l == r)
		return ;
	if (cdl_is_asc_order_range(&ps->stacks.a, l, r))
		return ;
	ft_pb_and_rotate_a(ps, &l, r, is_first);
	sort_b(ps, l, r);
}

static void
	sort_b(t_pushswap *ps, int l, int r)
{
	int	pivot_id;
	int	ret;

	if (cdl_is_empty(&ps->stacks.b))
		return ;
	ft_rotate_a(ps, l - 1);
	pivot_id = ((int64_t)l + (int64_t)r) / 2;
	ret = ft_pa_and_rotate_b(ps, l, r, pivot_id);
	if (!ret)
		return (ft_exit_failure(ps));
	if (l == r || ret == SORTED)
		return ;
	sort_a(ps, pivot_id, r, FALSE);
}

static void
	sort_7(t_pushswap *ps, int l, int r)
{
	int	pivot_id;

	if (l == r)
		return ;
	pivot_id = ((int64_t)l + (int64_t)r) / 2;
	sort_a(ps, l, pivot_id, TRUE);
	sort_a(ps, pivot_id, r, FALSE);
}

void
	ft_sort_7(t_pushswap *ps)
{
	t_dlist	*a;
	size_t	size;

	a = &ps->stacks.a;
	if (cdl_is_sorted(a->head, a->head->next, ft_is_asc_order))
		return ;
	size = cdl_size(a);
	if (size)
		sort_7(ps, 0, size - 1);
	ft_rotate_a_until_min(ps);
}
