/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quesera <quesera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:45:25 by quesera           #+#    #+#             */
/*   Updated: 2023/06/08 03:36:37 by quesera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_pivot(t_stack *stack, t_info *info, size_t num, t_set flag)
{
	int	*arr;

	if (flag == STACK_A)
		arr = ft_subnum(stack->a, stack->a_len - num, num);
	else
		arr = ft_subnum(stack->b, stack->b_len - num, num);
	q_sort(arr, 0, num - 1);
	for(int i = 0; i < num; i++)
		printf("arr[%d] : %d\n", i, arr[i]);
	info->p1 = arr[num / 3];
	info->p2 = arr[num / 3 * 2];
	info->ra = 0;
	info->rb = 0;
	info->pa = 0;
	info->pb = 0;
	printf("[p1] : %lu\t[p2] : %lu\n", num / 3, num / 3 * 2);
	printf("p1 : %zu\tp2 : %zu\n", info->p1, info->p2);
	free(arr);
}

void	sort_rr(t_stack *stack, t_info *info)
{
	// printf("sort_rr\n");
	size_t	i;

	i = -1;
	while (++i < info->ra && i < info->rb)
	{
		command(RRA, stack, info);
		command(RRB, stack, info);
	}
	while (i < info->ra)
	{
		command(RRA, stack, info);
		i++;
	}
	while (i < info->rb)
	{
		command(RRB, stack, info);
		i++;
	}
}

int	*ft_subnum(int *arr, size_t start, size_t num)
{
	int		*temp;
	size_t	i;

	i = -1;
	temp = (int *)malloc(sizeof(int) * num);
	while (++i < num)
		temp[i] = arr[start + i];
		printf(">>>  >>  subnum\n");
	for(int i = 0; i < num; i++)
		printf("temp[%d] : %d\t%d\n", i, temp[i], arr[start + i]);
	return (temp);
}