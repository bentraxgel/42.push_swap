/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quesera <quesera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:44:07 by seok              #+#    #+#             */
/*   Updated: 2023/06/04 20:57:16 by quesera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sort(t_stack *stack, t_set flag, size_t num)
{
	t_info	hard;

	if (num <= 3)
		mini_sort(stack, &hard, flag, num);
	else
	{
		if (flag == STACK_A)
		{
			if (stack->a_len == num)
				a_large_only(stack, num);
			else
				a_large_another(stack, num);
		}
		else
		{
			if (stack->b_len == num)
				b_large_only(stack, num);
			else
				b_large_another(stack, num);
		}
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

void	mini_sort(t_stack *stack, t_info *hard, size_t flag, size_t num)
{
	if (num == 1)
		return ;
	else if (num == 2)
		two_sort(stack, hard, flag);
	else
	{
		if (flag == STACK_A)
		{
			if (stack->a_len == num)
				a_three_only(stack, hard, stack->a_len - 1);
			else
				a_three_another(stack, hard, stack->a_len - 1);
		}
		else
		{
			if (stack->b_len == num)
				b_three_only(stack, hard, stack->b_len - 1);
			else
				b_three_another(stack, hard, stack->b_len - 1);
		}
	}
}

void	one_pivot(t_stack *stack, t_info *hard, size_t num, t_set flag)
{
	char	*arr;

	if (flag == STACK_A)
	{
		arr = ft_subnum(stack->a, stack->a_len - num, num);
		q_sort(arr);
		if (num == 4)
			hard->p0 = arr[1];
		else
			hard->p0 = arr[num / 2];
	}
	else
	{
		arr = ft_subnum(stack->b, stack->b_len - num, num);
		q_sort(arr);
		if (num == 6)
			hard->p0 = arr[2];
		else
			hard->p0 = arr[num / 2];
	}
	hard->ra = 0;
	hard->rb = 0;
	hard->pa = 0;
	hard->pb = 0;
}
