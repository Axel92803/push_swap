 #include "../../inc/push_swap.h"

double disorder_calc(int *nums, int size)
{
	int	i;
	int	j;
	int mistakes;
	int total_pairs;

	if (!nums || size <= 1)
		return (0);
	i = 0;
	mistakes = 0;
	total_pairs = ((size * (size - 1)) / 2);
	while(i < size)
	{	
		j = i + 1;
		while (j < size)
		{
			if(nums[i] > nums[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return ((double)mistakes / total_pairs);
}
