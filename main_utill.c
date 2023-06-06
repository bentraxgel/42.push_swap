/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quesera <quesera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:36:14 by seok              #+#    #+#             */
/*   Updated: 2023/06/06 14:47:26 by quesera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	my_error(void)
{
	write(2, "ERROR\n", 6);
	exit(false);
}

void	stack_indexing(t_stack *stack, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	int		*tmp;

	i = 0;
	tmp = alloc_guard(sizeof(int), len + 1);
	while(i < len)
	{
		j = 0;
		while (j < len)
		{
			if (stack->a[start + i] > stack->a[start + j])
				tmp[i] += 1;
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < len)
		stack->a[start + i] = tmp[i] + 1;
	free(tmp);
}

int	a_sort_check(int *arr, size_t len)
{
	printf("a_sort_check\n");
	size_t	i;

	i = 1;
	while (i < len)
	{
		if (arr[len - i] + 1 == arr[len - i - 1])
			i++;
		else
			return (false);
	}
	printf("\t\tTRUE\n");
	return (true);
}

int	b_sort_check(int *arr, size_t len)
{
	printf("b_sort_check\n");
	size_t	i;

	i = 0;
	while (i + 1 < len)
	{
		if (arr[i] + 1 == arr[i + 1])
			i++;
		else
			return (false);
	}
	printf("\t\tTRUE\n");
	return (true);
}

int	duplicate_check(int *arr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while(j < len)
		{
			if (arr[i] == arr[j])
				return(false);
			j++;
		}
		i++;
	}
	return (true);
}
