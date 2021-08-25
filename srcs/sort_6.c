/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:10:00 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/25 02:35:04 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	swap_first_value(t_pushswap *ps, size_t size)
{
	t_dlist	*a;

	a = &ps->stacks.a;
	if (4 < size
		&& !cdl_is_sorted(
			a->head, a->head->next, ft_is_ascending_order)
		&& cdl_is_sorted(
			a->head, a->head->next->next, ft_is_ascending_order))
		ft_ss(a, NULL, ps);
}

static int
	pb_and_rotate2(t_pushswap *ps, size_t size)
{
	int		ret;
	t_dlist	*a;

	ret = 1;
	a = &ps->stacks.a;
	while (ret != SORTED && ret)
	{
		size = cdl_size(a);
		if (size <= 3)
			break ;
		if (size == 4)
			ft_sort_4(a, ps);
		ret = ft_pb_min(ps);
		if (!ret)
			return (ret);
	}
	if (ret != SORTED && ret)
		ft_sort_3(ps);
	return (ret);
}

static int
	pb_and_rotate(t_pushswap *ps, size_t size)
{
	int		ret;
	t_dlist	*a;

	ret = 1;
	a = &ps->stacks.a;
	if (4 < size && !ft_check_circular_sorted(a, NULL)
		&& ft_check_circular_sorted(a, cdl_get_max_node(a)))
	{
		ret = ft_pb_max(ps);
		if (!ret)
			return (ret);
		return (ft_rotate_a_until_min(ps));
	}
	return (pb_and_rotate2(ps, size));
}

void
	ft_sort_6(t_pushswap *ps)
{
	size_t	size;
	int		ret;

	ret = 1;
	size = cdl_size(&ps->stacks.a);
	swap_first_value(ps, size);
	ret = pb_and_rotate(ps, size);
	while (ret && !cdl_is_empty(&ps->stacks.b))
		ft_pa(&ps->stacks.a, &ps->stacks.b, ps);
	if (!ret || !ft_rotate_a_until_min(ps))
		ft_exit_failure(ps);
}
