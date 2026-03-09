#include "../../inc/push_swap.h"

void	swap_n(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int  partition(int *arr, int low, int high)
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
		}
		j++;
	}
	swap_n(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int *arr, int low, int high)
{
	int p;

	if (low < high)
	{
		p = partition(arr, low, high);
		quick_sort(arr, low, p - 1);
		quick_sort(arr, p + 1, high);
	}
}
