/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:08:49 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/27 02:57:04 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	ra_or_rb(t_dlist *dlist)
{
	int	next_id;
	int	next_n;

	next_id = dlist->head->next->id;
	next_n = dlist->head->next->n;
	dlist->head->id = next_id;
	dlist->head->n = next_n;
	dlist->head->next->id = -1;
	dlist->head->next->n = 0;
	dlist->head = dlist->head->next;
}

static void
	rr(t_dlist *a, t_dlist *b)
{
	ra_or_rb(a);
	ra_or_rb(b);
}

void
	ft_rr(t_dlist *a, t_dlist *b, t_pushswap *ps, t_bool should_store_ans)
{
	char	*op;

	if (b == NULL)
	{
		ra_or_rb(a);
		if (should_store_ans == TRUE)
			op = ft_strdup(OP_RA);
	}
	else if (a == NULL)
	{
		ra_or_rb(b);
		if (should_store_ans == TRUE)
			op = ft_strdup(OP_RB);
	}
	else
	{
		rr(a, b);
		if (should_store_ans == TRUE)
			op = ft_strdup(OP_RR);
	}
	if (should_store_ans == TRUE && !op)
		ft_exit_failure(ps);
	else if (should_store_ans == TRUE)
		ft_add_ans(ps, op);
}
