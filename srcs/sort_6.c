/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:10:00 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/20 11:10:00 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	swap_firt_value(t_stacks *stacks, size_t size)
{
	if (4 < size
		&& !cdl_is_sorted(
			stacks->a.head, stacks->a.head->next, ft_is_ascending_order)
		&& cdl_is_sorted(
			stacks->a.head, stacks->a.head->next->next, ft_is_ascending_order))
		ft_ss(&stacks->a, NULL);
}

static int
	push_to_b_and_rotate(t_stacks *stacks, size_t size)
{
	int	ret;

	ret = 1;
	if (4 < size && !ft_check_circular_sorted(&stacks->a, NULL)
		&& ft_check_circular_sorted(&stacks->a, cdl_get_max_node(&stacks->a)))
	{
		ret = ft_push_max(stacks);
		if (!ret)
			return (ret);
		return (ft_rotate_a_until_min(stacks));
	}
	while (ret != SORTED && ret)
	{
		size = cdl_size(&stacks->a);
		if (size <= 3)
			break ;
		if (size == 4)
			ft_sort_4(&stacks->a);
		ret = ft_push_min(stacks);
		if (!ret)
			return (ret);
	}
	if (ret != SORTED && ret)
		ft_sort_3(&stacks->a);
	return (ret);
}

void
	ft_sort_6(t_stacks *stacks)
{
	size_t	size;
	int		ret;

	ret = 1;
	size = cdl_size(&stacks->a);
	swap_firt_value(stacks, size);
	ret = push_to_b_and_rotate(stacks, size);
	while (ret && stacks->b.head->next != stacks->b.head)
		ret = ft_pa(&stacks->a, &stacks->b);
	if (!ret || !ft_rotate_a_until_min(stacks))
		ft_exit_failure(stacks);
}
