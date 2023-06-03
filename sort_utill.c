/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:45:25 by quesera           #+#    #+#             */
/*   Updated: 2023/06/03 19:52:43 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sort(t_stack *stack, t_set flag, size_t num)
{
	t_info hard;

	if (num <= 3)
		mini_sort(stack, &hard, flag, num);
	else
	{
		if (flag == STACK_A)
			a_hard_sort();
		else
			b_hard_sort();
	}
}

void	two_sort(t_stack *stack, t_info *hard, t_set flag)
{
	if (flag == STACK_A)
	{
		if (stack->a[stack->a_len - 1] < stack->a[stack->a_len - 2])
			return ;
		else if (stack->a[stack->a_len - 1] > stack->a[stack->a_len - 2])
			command(SA, stack, hard);
	}
	else if (flag == STACK_B)
	{
		if (stack->b[stack->b_len - 1] > stack->b[stack->b_len - 2])
			return ;
		else if (stack->b[stack->b_len - 1] < stack->b[stack->b_len - 2])
			command(SB, stack, hard);
	}
}

void	save_pivot(t_stack *stack, t_info *info, size_t num, t_set flag)
{
	int	*arr;

	if (flag == STACK_A)
	{
		arr = ft_substr(stack->a, stack->a_len - num, num);
		q_sort(arr);
		info->p1 = arr[stack->a_len / 3];
		info->p2 = arr[stack->a_len / 3 * 2];
	}
	else
	{
		arr = ft_substr(stack->a, stack->a_len - num, num);
		q_sort(arr);
		info->p1 = arr[stack->a_len / 3];
		info->p2 = arr[stack->a_len / 3 * 2];
	}
	info->ra = 0;
	info->rb = 0;
	info->pa = 0;
	info->pb = 0;
}

void	sort_rr(t_stack *stack, t_info *info)
{
	// printf("sort_rr\n");
	size_t	i;

	i = -1;
	while (++i < info->ra && i < info->rb)
	{
		// printf("i : %zu\tra : %d\trb : %d\n", i, info->ra, info->rb);
		command(RRA, stack, info);
		command(RRB, stack, info);
	}
	while (i < info->ra)
	{
		command(RRA, stack, info);
		i++;
	}
	while (i < info->rb){
		command(RRB, stack, info);
		i++;
		}
}