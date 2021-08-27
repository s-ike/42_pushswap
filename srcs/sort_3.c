/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:09:46 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/27 02:31:33 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
if (y < x && x < z)      // 2,1,3
else if (z < y && y < x) // 3.2.1
else if (y < z && z < x) // 3,1,2
else if (x < z && z < y) // 1,3,2
else if (z < x && x < y) // 2,3,1
*/
void
	ft_sort_3(t_pushswap *ps)
{
	int	x;
	int	y;
	int	z;

	x = ps->stacks.a.head->next->n;
	y = ps->stacks.a.head->next->next->n;
	z = ps->stacks.a.head->next->next->next->n;
	if (y < x && x < z)
		ft_ss(&ps->stacks.a, NULL, ps, TRUE);
	else if (z < y && y < x)
	{
		ft_ss(&ps->stacks.a, NULL, ps, TRUE);
		ft_rrr(&ps->stacks.a, NULL, ps, TRUE);
	}
	else if (y < z && z < x)
		ft_rr(&ps->stacks.a, NULL, ps, TRUE);
	else if (x < z && z < y)
	{
		ft_ss(&ps->stacks.a, NULL, ps, TRUE);
		ft_rr(&ps->stacks.a, NULL, ps, TRUE);
	}
	else if (z < x && x < y)
		ft_rrr(&ps->stacks.a, NULL, ps, TRUE);
}
