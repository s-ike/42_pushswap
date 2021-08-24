/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:08:49 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/25 02:06:07 by sikeda           ###   ########.fr       */
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

int
	ft_rr(t_dlist *a, t_dlist *b, t_pushswap *ps)
{
	char	*op;

	if (b == NULL)
	{
		ra_or_rb(a);
		op = ft_strdup(OP_RA);
	}
	else if (a == NULL)
	{
		ra_or_rb(b);
		op = ft_strdup(OP_RB);
	}
	else
	{
		rr(a, b);
		op = ft_strdup(OP_RR);
	}
	if (!op)
		return (0);
	return (ft_add_ans(ps, op));
}
