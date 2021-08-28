/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:10:11 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/25 00:27:27 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_sort(t_pushswap *ps)
{
	size_t	size;

	size = cdl_size(&ps->stacks.a);
	if (size <= 1)
		return ;
	if (size == 2)
		ft_sort_2(ps);
	else if (size == 3)
		ft_sort_3(ps);
	else if (size <= 6)
		ft_sort_6(ps);
	else
		ft_sort_7(ps);
}
