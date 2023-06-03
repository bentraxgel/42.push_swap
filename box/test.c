#include <stdio.h>
#include <stdlib.h>

void	leaks()
{
	system("leaks -q a.out");
}

int	main()
{
	atexit(leaks);
	char	*arr;
	free(arr);
	arr = malloc(sizeof(char) * 10);
	free(arr);
	arr = "test";
	printf("arr : %s\n", arr);
}