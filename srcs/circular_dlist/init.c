/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:45:37 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/24 21:46:31 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_dlist.h"

int
	cdl_init_dlist(t_dlist *dlist)
{
	t_dnode	*dummy_node;

	dummy_node = (t_dnode *)ft_calloc(1, sizeof(t_dnode));
	if (!dummy_node)
		return (0);
	dummy_node->id = -1;
	dlist->head = dummy_node;
	dummy_node->prev = dummy_node;
	dummy_node->next = dummy_node;
	return (1);
}
