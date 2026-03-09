#include "../../inc/push_swap.h"

static int *copy_array(int *arr, int size)
{
	int *copy;
	int i;

	copy = (int *)malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}

static void	validate_duplicates(int *num_arr, int size, char ***args)
{
	int	*sorted_arr;

	sorted_arr = copy_array(num_arr, size);
	if (!sorted_arr)
	{
		free(num_arr);
		free_all_args(args);
		err();
	}
	quick_sort(sorted_arr, 0, size - 1);
	if (dup_err(sorted_arr, size))
	{
		free(sorted_arr);
		free(num_arr);
		free_all_args(args);
		err();
	}
	free(sorted_arr);
}

static void	fill(char ***args, int *num_arr)
{
	int	i;
	int j;
	int	z;

	i = 0;
	z = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			process_num(args[i][j], num_arr, args, &z);
			j++;
		}
		i++;
	}
}

int	*parse_num(char ***args, int size)
{
	int	*num_arr;

	num_arr = (int *)malloc(sizeof(int) * size);
	if (!num_arr)
	{
		free_all_args(args);
		err();
	}
	fill(args, num_arr);
	validate_duplicates(num_arr, size, args);
	return (num_arr);
}
