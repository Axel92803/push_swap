#include "../../inc/push_swap.h"

static void	free_block(char **sub_args)
{
	size_t	i;

	if (!sub_args)
		return ;
	i = 0;
	while (sub_args[i])
	{
		free(sub_args[i]);
		i++;
	}
	free(sub_args);
}

void free_args(char ***args, int index)
{

	int	i;

	i = 0;
	while (i < index)
	{
		free_block(args[i]);
		i++;
	}
	free(args);
}
