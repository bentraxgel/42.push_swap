/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quesera <quesera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 09:26:08 by quesera           #+#    #+#             */
/*   Updated: 2023/06/07 12:59:51 by quesera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_stack_sort(t_stack *stack, size_t num)
{
	size_t	i;
	t_info	info;

	a_sort_check(stack->a, stack->a_len);
	if (num <= 6)
	{
		hard_sort(stack, STACK_A, num);
		return ;
	}
	two_pivot(stack, &info, num, STACK_A);
	i = 0;
	while (i++ < stack->a_len)
	{
		if (stack->a[stack->a_len - 1] > info.p2)
			command(RA, stack, &info);
		else
		{
			command(PB, stack, &info);
			if (stack->a[stack->a_len - 1] <= info.p1)
				command(RB, stack, &info);
		}
	}
	sort_rr(stack, &info);
	printf("\t1^ pb : %zu\trb : %zu = %zu\n", info.pb, info.rb, info.pb - info.rb);
	a_stack_sort(stack, info.ra);
	printf("\t2^ pb : %zu\trb : %zu = %zu\n", info.pb, info.rb, info.pb - info.rb);
	b_stack_sort(stack, info.rb);
	printf("\t3^ pb : %zu\trb : %zu = %zu\n", info.pb, info.rb, info.pb - info.rb);
	b_stack_sort(stack, info.pb - info.rb);
}

void	b_stack_sort(t_stack *stack, size_t num)
{
	size_t	i;
	t_info	info;

	b_sort_check(stack->b, stack->b_len);
	if (num <= 6)
	{
		hard_sort(stack, STACK_B, num);
		return ;
	}
	two_pivot(stack, &info, num, STACK_B);
	i = 0;
	while (i++ < stack->b_len)
	{
		if (stack->b[stack->b_len - 1] <= info.p1)
			command(RB, stack, &info);
		else
		{
			command(PA, stack, &info);
			if (stack->b[stack->b_len - 1] <= info.p2)
				command(RA, stack, &info);
		}
	}
	a_stack_sort(stack, info.pa - info.ra);
	sort_rr(stack, &info);
	a_stack_sort(stack, info.ra);
	b_stack_sort(stack, info.rb);
}