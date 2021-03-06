/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:09:38 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/27 02:31:14 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_sort_2(t_pushswap *ps)
{
	int	x;
	int	y;

	x = ps->stacks.a.head->next->n;
	y = ps->stacks.a.head->next->next->n;
	if (y < x)
		ft_ss(&ps->stacks.a, NULL, ps, TRUE);
}
