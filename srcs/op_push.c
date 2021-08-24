/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:08:45 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/25 02:05:59 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	ft_pa(t_dlist *a, t_dlist *b, t_pushswap *ps)
{
	int		ret;
	char	*op;

	ret = cdl_add_front_dlist(a, b->head->next->n, b->head->next->id);
	op = NULL;
	if (ret)
	{
		cdl_remove_front(b);
		op = ft_strdup(OP_PA);
	}
	if (!op)
		return (0);
	return (ft_add_ans(ps, op));
}

int
	ft_pb(t_dlist *a, t_dlist *b, t_pushswap *ps)
{
	int		ret;
	char	*op;

	ret = cdl_add_front_dlist(b, a->head->next->n, a->head->next->id);
	op = NULL;
	if (ret)
	{
		cdl_remove_front(a);
		op = ft_strdup(OP_PB);
	}
	if (!op)
		return (0);
	return (ft_add_ans(ps, op));
}
