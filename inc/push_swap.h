#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../utils/ft_printf/ft_printf.h"
# include "../utils/GNL/get_next_line.h"
# include "../utils/libft/libft.h"

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

/*COMMANDS*/

void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);


/*UTILS*/

t_node *find_last(t_node *stack);


#endif
