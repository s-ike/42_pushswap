/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:43:35 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/28 16:46:54 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"
# include "circular_dlist.h"
# include "get_next_line.h"
# include "t_bool.h"

# define MSG_ERR "Error"
# define MSG_CHECKER_OK "OK"
# define MSG_CHECKER_KO "KO"

# define OP_SA "sa"
# define OP_SB "sb"
# define OP_SS "ss"
# define OP_PA "pa"
# define OP_PB "pb"
# define OP_RA "ra"
# define OP_RB "rb"
# define OP_RR "rr"
# define OP_RRA "rra"
# define OP_RRB "rrb"
# define OP_RRR "rrr"

# define SORTED -1
# define SORTSIZE 7
# define RB_SIZE 9

# define LR 2
# define L 0
# define R 1

typedef enum e_prg_name
{
	PG_PUSHSWAP,
	PG_CHECKER
}	t_prg_name;

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

typedef struct s_pushswap
{
	t_prg_name	prg;
	t_stacks	stacks;
	t_list		*ans;
}	t_pushswap;

/* ans_list.c */
void	ft_add_ans(t_pushswap *ps, char *op);
int		ft_optimize_ans(t_list *ans);
/* exit.c */
void	ft_exit_failure(t_pushswap *ps);
void	ft_exit_success(t_pushswap *ps);
/* init.c */
int		ft_make_stack_a(t_stacks *stacks, t_list **sort_list);
void	ft_terminate_stacks(t_stacks *stacks);
int		ft_init_pushswap(t_pushswap *ps, t_prg_name prg_name);
/* op_push.c */
void	ft_pa(t_dlist *a, t_dlist *b, t_pushswap *ps, t_bool should_store_ans);
void	ft_pb(t_dlist *a, t_dlist *b, t_pushswap *ps, t_bool should_store_ans);
/* op_rotate.c */
void	ft_rr(t_dlist *a, t_dlist *b, t_pushswap *ps, t_bool should_store_ans);
/* op_rrotate.c */
void	ft_rrr(t_dlist *a, t_dlist *b, t_pushswap *ps, t_bool should_store_ans);
/* op_swap.c */
void	ft_ss(t_dlist *a, t_dlist *b, t_pushswap *ps, t_bool should_store_ans);
/* order.c */
int		ft_is_asc_order(int x, int y);
/* presort_list.c */
int		ft_make_sort_list(t_list **sort_list, int argc, char **argv);
/* sort_2.c */
void	ft_sort_2(t_pushswap *ps);
/* sort_3.c */
void	ft_sort_3(t_pushswap *ps);
/* ft_sort_3_b_and_pa.c */
void	ft_sort_3_b_and_pa(t_pushswap *ps);
/* sort_4.c */
void	ft_sort_4(t_dlist *a, t_pushswap *ps);
/* sort_6.c */
void	ft_sort_6(t_pushswap *ps);
/* sort_6_b.c */
void	ft_sort_6_b(t_pushswap *ps);
/* sort_7.c */
void	ft_rotate_a(t_pushswap *ps, int end_id);
void	ft_sort_7(t_pushswap *ps);
/* sort_7_pa.c */
int		ft_pa_and_rotate_b(t_pushswap *ps, int l, int r, int pivot_id);
/* sort_7_pa2.c */
void	ft_pa_and_rotate_b_loop(
			t_pushswap *ps, int *not_targets, t_bool not_targets_flag, int *id);
/* sort_7_pb.c */
void	ft_pb_and_rotate_a(t_pushswap *ps, int *l, int r, t_bool is_first);
/* sort_6_utils.c */
int		ft_check_circular_sorted(t_dlist *dlist, t_dnode *skip);
int		ft_rotate_a_until_min(t_pushswap *ps);
int		ft_pb_max(t_pushswap *ps);
int		ft_pb_min(t_pushswap *ps);
/* sort.c */
void	ft_sort(t_pushswap *ps);
/* stack.c */
void	ft_ra_or_rr(t_pushswap *ps, int target);
char	*ft_get_rotate_op(
			t_dlist *dlist, size_t target_node_idx, char stack_name);
void	ft_rotate_by_op(t_pushswap *ps, const char *op);
void	ft_rotate(t_pushswap *ps, size_t target_node_idx, char stack_name);
/* validator.c */
int		ft_check_dup_n(t_list **sort_list);
int		ft_is_valid_args(int argc, char **argv);
/* utils/tlist_sort.c */
void	ft_sort_list(t_list **lst, int64_t f(t_list *left, t_list *right));
/* utils/utils.c */
int		ft_isspace(char c);

#endif