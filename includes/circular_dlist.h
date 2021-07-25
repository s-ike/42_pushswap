#ifndef CIRCULAR_DLIST_H
# define CIRCULAR_DLIST_H

# include "libft.h"

typedef struct s_dnode
{
	int				n;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}	t_dnode;

typedef struct s_dlist
{
	t_dnode	*head;
	t_dnode	*crnt;
}	t_dlist;

/* cicular_dlist.c */
int		cdl_init_dlist(t_dlist *dlist);
int		cdl_add_front_dlist(t_dlist *dlist, int n);
int		cdl_add_back_dlist(t_dlist *dlist, int n);
t_dnode	*cdl_search(t_dlist *dlist, int x, int compare(int x, int y));
t_dnode	*cdl_get_max_node(t_dlist *dlist);
t_dnode	*cdl_get_min_node(t_dlist *dlist);
size_t	cdl_get_max_node_idx(t_dlist *dlist);
size_t	cdl_get_min_node_idx(t_dlist *dlist);
int		cdl_is_sorted(t_dnode *head, t_dnode *start, int compare(int x, int y));
size_t	cdl_size(const t_dlist *dlist);
void	cdl_print_dlist(const t_dlist *dlist);
void	cdl_remove_front(t_dlist *dlist);
void	cdl_clear(t_dlist *dlist);
void	cdl_terminate(t_dlist *dlist);

#endif
