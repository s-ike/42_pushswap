/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:45:44 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/24 21:46:03 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_dlist.h"

static void
	remove_node(t_dnode *p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

void
	cdl_remove_front(t_dlist *dlist)
{
	if (!cdl_is_empty(dlist))
		remove_node(dlist->head->next);
}

void
	cdl_clear(t_dlist *dlist)
{
	while (!cdl_is_empty(dlist))
		cdl_remove_front(dlist);
}

void
	cdl_terminate(t_dlist *dlist)
{
	cdl_clear(dlist);
	free(dlist->head);
}
