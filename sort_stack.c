/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 09:26:08 by quesera           #+#    #+#             */
/*   Updated: 2023/06/03 19:50:31 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_stack_sort(t_stack *stack, size_t num)
{
	size_t	i;
	t_info	info;

	i = -1;
	a_sort_check(stack->a, stack->a_len);
	if (num <= 6)
	{
		hard_sort(stack, STACK_A, num);
		return ;
	}
	save_pivot(stack, &info, num, STACK_A);
	while (++i < stack->a_len)
	{
		if (stack->a[stack->a_len - i] > info.p2)
			command(RA, stack, &info);
		else
		{
			command(PB, stack, &info);
			if (stack->a[stack->a_len - i] <= info.p1)
				command(RB, stack, &info);
		}
	}
	sort_rr(stack, &info);
	a_stack_sort(stack, info.ra);
	b_stack_sort(stack, info.rb);
	b_stack_sort(stack, info.pb - info.rb);
}

void	b_stack_sort(t_stack *stack, size_t num)
{
	size_t	i;
	t_info	info;

	i = -1;
	b_sort_check(stack->b, stack->b_len);
	if (num <= 6)
	{
		hard_sort(stack, &info, STACK_B, num);
		return ;
	}
	save_pivot(stack, &info, num, STACK_B);
	while (++i < stack->b_len)
	{

	}
}