/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:44:56 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/14 03:44:56 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_dlist.h"

static int
	insert_after(t_dlist *dlist, t_dnode *prev, int n, int id)
{
	t_dnode	*new_node;
	t_dnode	*next;

	new_node = (t_dnode *)ft_calloc(1, sizeof(t_dnode));
	if (!new_node)
		return (0);
	next = prev->next;
	prev->next->prev = new_node;
	prev->next = new_node;
	new_node->id = id;
	new_node->n = n;
	new_node->prev = prev;
	new_node->next = next;
	dlist->crnt = new_node;
	return (1);
}

int
	cdl_add_front_dlist(t_dlist *dlist, int n, int id)
{
	return (insert_after(dlist, dlist->head, n, id));
}

int
	cdl_add_back_dlist(t_dlist *dlist, int n, int id)
{
	return (insert_after(dlist, dlist->head->prev, n, id));
}
