/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_dlist.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:44:45 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/14 03:44:46 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULAR_DLIST_H
# define CIRCULAR_DLIST_H

# include "libft.h"

typedef struct s_dnode
{
	int				id;
	int				n;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}	t_dnode;

typedef struct s_dlist
{
	t_dnode	*head;
	t_dnode	*crnt;
}	t_dlist;

/* add.c */
int		cdl_add_front_dlist(t_dlist *dlist, int n, int id);
int		cdl_add_back_dlist(t_dlist *dlist, int n, int id);
/* comp.c */
int		cdl_ncmp(int n1, int n2);
/* info.c */
int		cdl_is_empty(const t_dlist *dlist);
size_t	cdl_size(const t_dlist *dlist);
int		cdl_is_sorted(t_dnode *head, t_dnode *start, int compare(int x, int y));
int		cdl_is_sorted_asc_in_range(t_dlist *dlist, int start_id, int end_id);
/* init.c */
int		cdl_init_dlist(t_dlist *dlist);
/* print.c */
void	cdl_print_dlist(const t_dlist *dlist);
/* remove.c */
void	cdl_remove_front(t_dlist *dlist);
void	cdl_clear(t_dlist *dlist);
void	cdl_terminate(t_dlist *dlist);
/* search.c */
t_dnode	*cdl_get_node_by_id(t_dlist *dlist, int id);
t_dnode	*cdl_get_node_by_idx(t_dlist *dlist, size_t idx);
t_dnode	*cdl_search(t_dlist *dlist, int id, int compare(int x, int y));
t_dnode	*cdl_get_max_node(t_dlist *dlist);
t_dnode	*cdl_get_min_node(t_dlist *dlist);
/* search_idx.c */
size_t	cdl_get_idx_by_id(t_dlist *dlist, int id);
size_t	cdl_get_max_node_idx(t_dlist *dlist);
size_t	cdl_get_min_node_idx(t_dlist *dlist);

#endif
