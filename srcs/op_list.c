#include "push_swap.h"

int
	ft_add_op_to_ans(t_list **ans, char *op)
{
	t_list	*op_node;

	op_node = ft_lstnew(op);
	if (!op_node)
		return (0);
	ft_lstadd_back(ans, op_node);
	return (1);
}
