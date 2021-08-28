/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:10:20 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/27 02:35:15 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_ra_or_rr(t_pushswap *ps, int target)
{
	t_dlist	*a;
	t_dlist	*b;

	a = &ps->stacks.a;
	b = &ps->stacks.b;
	if (b->head->next->id == target)
		ft_rr(a, NULL, ps, TRUE);
	else if (2 < cdl_size(b) && b->head->prev->id == target)
	{
		ft_rr(a, NULL, ps, TRUE);
		ft_rrr(NULL, b, ps, TRUE);
	}
	else if (1 < cdl_size(b))
		ft_rr(a, b, ps, TRUE);
}

char
	*ft_get_rotate_op(t_dlist *dlist, size_t target_node_idx, char stack_name)
{
	size_t	proximity;
	size_t	size;

	size = cdl_size(dlist);
	proximity = size / 2;
	if (proximity < (size + 1) / 2)
		proximity = (size + 1) / 2;
	if (proximity < target_node_idx)
	{
		if (stack_name == 'a')
			return (OP_RRA);
		return (OP_RRB);
	}
	if (stack_name == 'a')
		return (OP_RA);
	return (OP_RB);
}

void
	ft_rotate_by_op(t_pushswap *ps, const char *op)
{
	t_dlist	*a;
	t_dlist	*b;

	a = &ps->stacks.a;
	b = &ps->stacks.b;
	if (!ft_strcmp(op, OP_RA))
		ft_rr(a, NULL, ps, TRUE);
	else if (!ft_strcmp(op, OP_RB))
		ft_rr(NULL, b, ps, TRUE);
	else if (!ft_strcmp(op, OP_RRA))
		ft_rrr(a, NULL, ps, TRUE);
	else if (!ft_strcmp(op, OP_RRB))
		ft_rrr(NULL, b, ps, TRUE);
	else if (!ft_strcmp(op, OP_RR))
		ft_rr(a, b, ps, TRUE);
	else if (!ft_strcmp(op, OP_RRR))
		ft_rrr(a, b, ps, TRUE);
}

void
	ft_rotate(t_pushswap *ps, size_t target_node_idx, char stack_name)
{
	char	*op;

	if (stack_name == 'a')
		op = ft_get_rotate_op(&ps->stacks.a, target_node_idx, stack_name);
	else
		op = ft_get_rotate_op(&ps->stacks.b, target_node_idx, stack_name);
	ft_rotate_by_op(ps, op);
}
