#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include "libft.h"
# include "circular_dlist.h"

# define MSG_ERR "Error"

# define SORTED -1

typedef struct s_stacks
{
	t_dlist	a;
	t_dlist	b;
}	t_stacks;

/* exit.c */
void	ft_exit_failure(t_stacks *stacks);
void	ft_exit_success(t_stacks *stacks);
void	ft_exit_success_with_leaks(t_stacks *stacks);
/* op_push.c */
int		ft_pa(t_dlist *a, t_dlist *b, int n);
int		ft_pb(t_dlist *a, t_dlist *b, int n);
/* op_rotate.c */
void	ft_rr(t_dlist *a, t_dlist *b);
/* op_rrotate.c */
void	ft_rrr(t_dlist *a, t_dlist *b);
/* op_swap.c */
void	ft_ss(t_dlist *a, t_dlist *b);
/* sort_2.c */
void	ft_sort_2(t_dlist *a);
/* sort_3.c */
void	ft_sort_3(t_dlist *a);
/* sort_3.c */
void	ft_sort_4(t_dlist *a);
/* sort_6.c */
void	ft_sort_6(t_stacks *stacks);
/* sort.c */
void	ft_sort(t_stacks *stacks);
/* stack.c */
int		ft_push(t_dlist *dlist, int n, const char *op);
int		ft_append_stack_while_check_dup(t_dlist *dlist, int n);
int		ft_init_stacks(t_stacks *stacks);
void	ft_terminate_stacks(t_stacks *stacks);
/* utils.c */
int		ft_isspace(char c);
/* validator.c */
bool	ft_is_valid_args(int argc, char **argv);

#endif