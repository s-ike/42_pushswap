/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:53:56 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/25 00:43:50 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	init_stacks(t_stacks *stacks)
{
	if (cdl_init_dlist(&stacks->a))
		return (cdl_init_dlist(&stacks->b));
	cdl_terminate(&stacks->a);
	return (0);
}

void
	ft_terminate_stacks(t_stacks *stacks)
{
	cdl_terminate(&stacks->a);
	cdl_terminate(&stacks->b);
	return ;
}

int
	ft_init_pushswap(t_pushswap *ps)
{
	if (init_stacks(&ps->stacks))
	{
		ps->ans = NULL;
		return (1);
	}
	return (0);
}
