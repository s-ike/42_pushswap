/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:10:11 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/21 00:40:19 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_sort(t_stacks *stacks)
{
	size_t	size;

	size = cdl_size(&stacks->a);
	if (size <= 1)
		return ;
	if (size == 2)
		ft_sort_2(&stacks->a);
	else if (size == 3)
		ft_sort_3(&stacks->a);
	else if (size <= 6)
		ft_sort_6(stacks);
	else
		ft_sort_7(stacks);
}
