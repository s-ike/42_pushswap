/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:08:45 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/25 02:23:46 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
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
		ft_exit_failure(ps);
	ft_add_ans(ps, op);
}

void
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
		ft_exit_failure(ps);
	ft_add_ans(ps, op);
}
