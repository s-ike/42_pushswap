/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:08:59 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/20 11:09:01 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	rra_or_rrb(t_dlist *dlist)
{
	int	prev_id;
	int	prev_n;

	prev_id = dlist->head->prev->id;
	prev_n = dlist->head->prev->n;
	dlist->head->id = prev_id;
	dlist->head->n = prev_n;
	dlist->head->prev->id = -1;
	dlist->head->prev->n = 0;
	dlist->head = dlist->head->prev;
}

static void
	rrr(t_dlist *a, t_dlist *b)
{
	rra_or_rrb(a);
	rra_or_rrb(b);
}

void
	ft_rrr(t_dlist *a, t_dlist *b)
{
	if (b == NULL)
	{
		rra_or_rrb(a);
		ft_putendl_fd("rra", STDOUT_FILENO);
	}
	else if (a == NULL)
	{
		rra_or_rrb(b);
		ft_putendl_fd("rrb", STDOUT_FILENO);
	}
	else
	{
		rrr(a, b);
		ft_putendl_fd("rrr", STDOUT_FILENO);
	}
}
