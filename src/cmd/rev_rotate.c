#include "../../inc/push_swap.h"

static void	rev_rotate(t_node **stack)
{
	if(!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}

void	rra(t_node **a)
{
	rev_rotate(a);
}

void	rrb(t_node **b)
{
	rev_rotate(b);
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
}

