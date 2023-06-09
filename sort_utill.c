/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:45:25 by quesera           #+#    #+#             */
/*   Updated: 2023/06/10 01:00:41 by seok             ###   ########.fr       */
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
	info->p1 = arr[num / 3];
	info->p2 = arr[num / 3 * 2];
	info->ra = 0;
	info->rb = 0;
	info->pa = 0;
	info->pb = 0;
	free(arr);
}

void	sort_rr(t_stack *stack, t_info *info, size_t num)
{
	size_t	i;

	i = 0;
	while (i < info->ra && i < info->rb)
	{
		command(RRA, stack, info);
		command(RRB, stack, info);
		++i;
	}
	while (stack->a_len != num && i < info->ra)
	{
		command(RRA, stack, info);
		i++;
	}
	while (stack->b_len != num && i < info->rb)
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
	return (temp);
}

//[p1] : 6	[p2] : 12
// p1 : 7	p2 : 13