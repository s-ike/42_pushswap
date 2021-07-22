#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include "libft.h"
# include "circular_dlist.h"

# define MSG_ERR "Error"

/* op_rotate.c */
void	ft_rr(t_dlist *a, t_dlist *b);
/* op_swap.c */
void	ft_ss(t_dlist *a, t_dlist *b);
/* sort_2.c */
void	ft_sort_2(t_dlist *a);
/* sort.c */
void	ft_sort(t_dlist *a);
/* stack.c */
int		ft_push(t_dlist *dlist, int n);
int		ft_append_stack_while_check_dup(t_dlist *dlist, int n);
int		ft_init_stack(t_dlist *dlist);
void	ft_terminate_stack(t_dlist *dlist);
/* utils.c */
int		ft_isspace(char c);
/* validator.c */
bool	ft_is_valid_args(int argc, char **argv);

#endif