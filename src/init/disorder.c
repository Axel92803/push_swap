#include "../../inc/push_swap.h"

double disorder_calc(int *nums, int size)
{
	int	i;
	int	j;
	int mistakes;
	int total_pairs;

	if (!nums)
		return (0);
	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while(i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs += 1;
			if(nums[i] > nums[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}
