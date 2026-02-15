#include "../../inc/push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*old;
	t_node	*last;

	if(!*stack || !(*stack)->next)
		return ;

	old = (*stack);
	last = find_last(*stack);

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	last->next = old;
	old->prev = last;
	old->next = NULL;
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
