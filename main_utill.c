/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:36:14 by seok              #+#    #+#             */
/*   Updated: 2023/06/01 18:59:40 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	my_error(void) //TODO ㅈㅏ료형 void에서 int로 바꿔본
{
	write(2, "ERROR\n", 6);
	exit(FALSE);
}

void	stack_indexing(t_stack *stack, size_t start, size_t len)
{
	size_t	i;
	size_t	j;
	int		*tmp;

	i = 0;
	tmp = ft_calloc(len + 1, sizeof(int));
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
//TODO del
// void	b_stack_indexing(t_stack *stack, size_t start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		*tmp;

// 	i = 0;
// 	tmp = ft_calloc(len + 1, sizeof(int));
// 	while(i < len)
// 	{
// 		j = 0;
// 		while (j < len)
// 		{
// 			if (stack->b[start + i] > stack->b[start + j])
// 				tmp[i] += 1;
// 			j++;
// 		}
// 		i++;
// 	}
// 	i = -1;
// 	while (++i < len)
// 		stack->b[start + i] = tmp[i];
// 	free(tmp);
// }

int	b_sort_check(int *arr, size_t len)
{
	printf("a_sort_check\n");
	size_t	i;

	i = 0;
	while (i + 1 < len)
	{
		if (arr[i] + 1 == arr[i + 1])
			i++;
		else
			return (FALSE);
	}
	printf("\t\tTRUE\n");
	return (TRUE);
}

int	a_sort_check(int *arr, size_t len)
{
	printf("b_sort_check\n");
	size_t	i;

	i = 1;
	while (i < len)
	{
		if (arr[len - i] + 1 == arr[len - i - 1])
			i++;
		else
			return (FALSE);
	}
	printf("\t\tTRUE\n");
	return (TRUE);
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
				return(FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}