#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../submodule_utils/ft_printf/ft_printf.h"
# include "../submodule_utils/GNL/get_next_line.h"
# include "../submodule_utils/libft/libft.h"

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
} t_strategy;

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

/*PARSING*/

char	***split_arg(int argc, char **argv);
int		count_args(char ***args);
int		parse_arg(int argc, char **argv, t_strategy *strategy);
int		parse_num(char ***args, t_node **a);

/*UTILS -- ERROR*/

int		syntax_err(char *argv);
int		dup_err(t_node **a, int num);
void	free_err(t_node **stack);
void	free_arr_err(int *arr);
void	free_args(char ***args, int index);

/*STACK*/

void	append_node(t_node **a, int num);
double	disorder_calc(int *nums, int size);

#endif
