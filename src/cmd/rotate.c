#include "../../inc/push_swap.h"

static void	rotate(t_node **stack)
{
	if(!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	ra(t_node **a)
{
	rotate(a);
}

void	rb(t_node **b)
{
	rotate(b);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}
