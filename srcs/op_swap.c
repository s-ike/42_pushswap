/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:09:04 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/27 02:57:42 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	sa_or_sb(t_dlist *dlist)
{
	int	tmp_id;
	int	tmp_n;

	tmp_id = dlist->head->next->id;
	tmp_n = dlist->head->next->n;
	dlist->head->next->id = dlist->head->next->next->id;
	dlist->head->next->n = dlist->head->next->next->n;
	dlist->head->next->next->id = tmp_id;
	dlist->head->next->next->n = tmp_n;
}

static void
	ss(t_dlist *a, t_dlist *b)
{
	sa_or_sb(a);
	sa_or_sb(b);
}

void
	ft_ss(t_dlist *a, t_dlist *b, t_pushswap *ps, t_bool should_store_ans)
{
	char	*op;

	if (b == NULL)
	{
		sa_or_sb(a);
		if (should_store_ans == TRUE)
			op = ft_strdup(OP_SA);
	}
	else if (a == NULL)
	{
		sa_or_sb(b);
		if (should_store_ans == TRUE)
			op = ft_strdup(OP_SB);
	}
	else
	{
		ss(a, b);
		if (should_store_ans == TRUE)
			op = ft_strdup(OP_SS);
	}
	if (should_store_ans == TRUE && !op)
		ft_exit_failure(ps);
	else if (should_store_ans == TRUE)
		ft_add_ans(ps, op);
}
