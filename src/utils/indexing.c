#include "../../inc/push_swap.h"

static int	*rank_arr(int size)
{
	int	i;
	int *arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return NULL;
	while (i < size)
	{
		arr[i] = i;
		i++;
	}
	return (arr);
}

void	swap_n(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int  partition(int *arr, int *rank_arr, int low, int high)
{
	int i;
	int j;
	int piv;

	i = low - 1;
	j = low;
	piv = arr[high];
	while (j < high)
	{
		if(arr[j] < piv)
		{
			i++;
			swap_n(&arr[i], &arr[j]);
			if (rank_arr)
				swap_n(&rank_arr[i], &rank_arr[j]);
		}
		j++;
	}
	swap_n(&arr[i + 1], &arr[high]);
	if (rank_arr)
		swap_n(&rank_arr[i + 1], &rank_arr[high]);
	return (i + 1);
}

void	quick_sort(int *arr, int *rank_arr, int low, int high)
{
	int p;

	if (low < high)
	{
		p = partition(arr, rank_arr, low, high);
		quick_sort(arr, rank_arr, low, p - 1);
		quick_sort(arr, rank_arr, p + 1, high);
	}
}

int	*rank_sort(int *arr, int size)
{
	int	*parallel_1;
	int	*parallel_2;
	int *arr_copy;

	parallel_1 = rank_arr(size);
	parallel_2 = rank_arr(size);
	arr_copy = copy_array(arr, size);
	if (!parallel_1 || !parallel_2 || !arr_copy)
	{
		free(parallel_1);
		free(parallel_2);
		free(arr_copy);
		err();

	}
	quick_sort(arr_copy, parallel_1, 0, size - 1);
	quick_sort(parallel_1, parallel_2, 0, size - 1);
	free(arr_copy);
	free(parallel_1);
	return (parallel_2);
}
