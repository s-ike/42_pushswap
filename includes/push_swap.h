/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:43:35 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/22 22:18:35 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"
# include "circular_dlist.h"
# include "t_bool.h"

# define MSG_ERR "Error"

# define OP_RA "ra"
# define OP_RB "rb"
# define OP_RR "rr"
# define OP_RRA "rra"
# define OP_RRB "rrb"
# define OP_RRR "rrr"

# define SORTED -1
# define SORTSIZE 7
/* rotate_b */
# define LR 2
# define L 0
# define R 1

typedef struct s_stacks
{
	t_dlist	a;
	t_dlist	b;
}	t_stacks;

typedef struct s_sort
{
	int	id;
	int	org_idx;
	int	n;
}	t_sort;

/* exit.c */
void	ft_exit_failure(t_stacks *stacks);
void	ft_exit_success(t_stacks *stacks);
/* op_push.c */
int		ft_pa(t_dlist *a, t_dlist *b);
int		ft_pb(t_dlist *a, t_dlist *b);
/* op_rotate.c */
void	ft_rr(t_dlist *a, t_dlist *b);
/* op_rrotate.c */
void	ft_rrr(t_dlist *a, t_dlist *b);
/* op_swap.c */
void	ft_ss(t_dlist *a, t_dlist *b);
/* order.c */
int		ft_is_ascending_order(int x, int y);
/* presort_list.c */
int		ft_make_sort_list(t_list **sort_list, int argc, char **argv);
/* sort_2.c */
void	ft_sort_2(t_dlist *a);
/* sort_3.c */
void	ft_sort_3(t_dlist *a);
/* ft_sort_3_b_and_pa.c */
int		ft_sort_3_b_and_pa(t_stacks *a);
/* sort_4.c */
void	ft_sort_4(t_dlist *a);
/* sort_6.c */
void	ft_sort_6(t_stacks *stacks);
/* sort_6_b.c */
void	ft_sort_6_b(t_stacks *stacks);
/* sort_7.c */
void	ft_rotate_a(t_stacks *stacks, int end_id);
void	ft_sort_7(t_stacks *stacks);
/* sort_7_pa.c */
int		ft_pa_and_rotate_b(t_stacks *stacks, int l, int r, int pivot_id);
/* sort_7_pb.c */
int		ft_pb_and_rotate_a(t_stacks *stacks, int *l, int r, t_bool is_first);
/* sort_6_utils.c */
int		ft_check_circular_sorted(t_dlist *dlist, t_dnode *skip);
int		ft_rotate_a_until_min(t_stacks *stacks);
int		ft_push_max(t_stacks *stacks);
int		ft_push_min(t_stacks *stacks);
/* sort.c */
void	ft_sort(t_stacks *stacks);
/* stack.c */
int		ft_init_stacks(t_stacks *stacks);
void	ft_terminate_stacks(t_stacks *stacks);
void	ft_ra_or_rr(t_stacks *stacks, int target);
char	*ft_get_rotate_op(t_dlist *dlist, size_t target_node_idx, char stack);
void	ft_rotate_by_op(t_stacks *stacks, const char *op);
void	ft_rotate(t_stacks *stacks, size_t target_node_idx, char stack_name);
/* validator.c */
int		ft_check_dup_n(t_list **sort_list);
int		ft_is_valid_args(int argc, char **argv);
/* utils/tlist_sort.c */
void	ft_sort_list(t_list **lst, int f(t_list *left, t_list *right));
/* utils/utils.c */
int		ft_isspace(char c);

#endif