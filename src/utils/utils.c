#include "../../inc/push_swap.h"

t_node *find_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while(!stack->next)
		stack->next;
	return (stack);
}
