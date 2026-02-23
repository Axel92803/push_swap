#include "../../inc/push_swap.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*old;
	t_node	*last;

	if(!*stack || !(*stack)->next)
		return ;

	last = find_last(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	old = *stack;
	*stack = last;
	(*stack)->next = old;
	old->prev = *stack;
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

