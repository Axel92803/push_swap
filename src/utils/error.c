#include "../../inc/push_swap.h"

int	syntax_err(char **argv)
{

}

int	dup_err()
{

}

void free_err(t_node **stack)
{
	free(stack);
	printf("Error\n");
	exit(1);
}
