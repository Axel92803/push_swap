#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../submodule_utils/libft/inc/libft.h"
# include <stdio.h>

typedef struct s_node
{
	int				val;
	int				index;
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

char		***split_arg(int argc, char **argv, int start, int *tot_len);
int			parse_arg(int argc, char **argv, t_strategy *strategy);
int			*parse_num(char ***args, int size);
void	process_num(char *str, int *num_arr, char ***args, int *z);

/*ERROR*/

int		syntax_err(char *argv);
int 	dup_err(int *sort_arr, int size);
void	free_err(t_node **stack);
void	err_free_args(char ***args, int index);
void	err(void);

/*UTILS*/

void	free_stack(t_node **stack);
void	abort_parse(char ***args, int *num_arr);
void	free_all_args(char ***args);
void	free_block(char **sub_args);

/*INDEXING*/

void    swap_n(int *a, int *b);
void    quick_sort(int *arr, int low, int high);


/*STACK*/

void	append_node(t_node **a, int num);
double	disorder_calc(int *nums, int size);

#endif
