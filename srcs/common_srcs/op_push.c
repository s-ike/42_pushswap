/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:08:45 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/27 02:26:42 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_pa(t_dlist *a, t_dlist *b, t_pushswap *ps, t_bool should_store_ans)
{
	int		ret;
	char	*op;

	ret = 1;
	if (!cdl_is_empty(b))
		ret = cdl_add_front_dlist(a, b->head->next->n, b->head->next->id);
	op = NULL;
	if (ret)
	{
		if (!cdl_is_empty(b))
			cdl_remove_front(b);
		if (should_store_ans == TRUE)
			op = ft_strdup(OP_PA);
	}
	if (should_store_ans == TRUE)
	{
		if (!op)
			ft_exit_failure(ps);
		ft_add_ans(ps, op);
	}
	else if (!ret)
		ft_exit_failure(ps);
}

void
	ft_pb(t_dlist *a, t_dlist *b, t_pushswap *ps, t_bool should_store_ans)
{
	int		ret;
	char	*op;

	ret = 1;
	if (!cdl_is_empty(a))
		ret = cdl_add_front_dlist(b, a->head->next->n, a->head->next->id);
	op = NULL;
	if (ret)
	{
		if (!cdl_is_empty(a))
			cdl_remove_front(a);
		if (should_store_ans == TRUE)
			op = ft_strdup(OP_PB);
	}
	if (should_store_ans == TRUE)
	{
		if (!op)
			ft_exit_failure(ps);
		ft_add_ans(ps, op);
	}
	else if (!ret)
		ft_exit_failure(ps);
}
