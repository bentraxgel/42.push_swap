#include <stdio.h>

int	is_sort(int *stack, int len)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack[i];
	while (++i < len)
	{
		if (stack[i] > tmp)
			return (0);
		tmp = stack[i];
	}
	return (1);
}

int	main()
{
	int	stack[5] = {10, 5, 0, -1, 2};
	printf("result : %d\n", is_sort(stack, 5));
}