#include "../push_swap.h"

int	main()
{
	t_stack stack;

	// stack.a = malloc(sizeof(int) * 10);
	int i = {5, 8, 2, 0, 1};
	printf("< before >\n");
	for (int i = 9; i >= 0; i--)
		printf("a[%d] : %d\n", i, stack.a[i]);
	a_large_only(&stack, 5);
	printf("< after >\n");
	for (int i = 9; i >= 0; i--)
		printf("a[%d] : %d\n", i, stack.a[i]);
}