/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 09:26:08 by quesera           #+#    #+#             */
/*   Updated: 2023/06/08 22:52:20 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_stack_sort(t_stack *stack, size_t num)
{
		printf("[%s:%d][%s]\n", __FILE__, __LINE__, __func__);
		printf("num : %zu\n", num);
	size_t	i;
	int		target;
	t_info	info;

	if (a_sort_check(stack->a, stack->a_len - num, num) == true)
		return ;
	if (num <= 6)
	{
		hard_sort(stack, STACK_A, num);
		return ;
	}
	two_pivot(stack, &info, num, STACK_A);
	i = 0;
	while (i++ < num)
	{
		target = stack->a[stack->a_len - 1];
		if (target > info.p2)
			command(RA, stack, &info);
		else
		{
			command(PB, stack, &info);
			if (target > info.p1)
			{
				command(RB, stack, &info);
				if (stack->b_len == 1)
					info.rb++;
			}
		}
	}
	sort_rr(stack, &info, num);
	a_stack_sort(stack, info.ra);
	b_stack_sort(stack, info.rb);
	b_stack_sort(stack, info.pb - info.rb);
}

void	b_stack_sort(t_stack *stack, size_t num)
{
	printf("[%s:%d][%s]\n", __FILE__, __LINE__, __func__);
	printf("num : %zu\n", num);
	size_t	i;
	int		target;
	t_info	info;

	if (b_sort_check(stack->b, stack->b_len - num, num) == true)
	{
		while (num--)
			command(PA, stack, &info);
		printf("b_check : END\n");
		return ;
	}
	if (num <= 6)
	{
		printf("b_mini\n");
		hard_sort(stack, STACK_B, num);
		printf("hard END\n");
		while (num--)
			command(PA, stack, &info);
		return ;
	}
	two_pivot(stack, &info, num, STACK_B);
	i = 0;
	while (i++ < num)
	{
		target = stack->b[stack->b_len - 1];
		if (target <= info.p1)
			command(RB, stack, &info);
		else
		{
			command(PA, stack, &info);
			if (target <= info.p2)
			{
				command(RA, stack, &info);
				if (stack->a_len == 1)
					info.ra++;
			}
		}
	}
	a_stack_sort(stack, info.pa - info.ra);
	sort_rr(stack, &info, num);
	a_stack_sort(stack, info.ra);
	b_stack_sort(stack, info.rb);
}