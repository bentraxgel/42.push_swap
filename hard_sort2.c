/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quesera <quesera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:33:14 by seok              #+#    #+#             */
/*   Updated: 2023/06/04 18:49:39 by quesera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_large_only(t_stack *stack, size_t num)
{
	t_info	hard;
	size_t	i;

	hard.a = 3;
	hard.b = num - 3;
	i = 0;
	while (i++ < hard.b)
		command(PB, stack, &hard);
	mini_sort(stack, &hard, STACK_A, hard.a);
	mini_sort(stack, &hard, STACK_B, hard.b);
	while (hard.a + hard.b > 0)
	{
		if (hard.a == 0)
			hard.b -= command(PA, stack, &hard);
		else if (hard.b == 0)
			hard.a -= command(RRA, stack, &hard);
		else if (stack->a[0] < stack->b[stack->b_len - 1])
			hard.b -= command(PA, stack, &hard);
		else if (stack->a[0] > stack->b[stack->b_len - 1])
			hard.a -= command(RRA, stack, &hard);
	}
}

void	a_large_another(t_stack *stack, size_t num)
{
	t_info	hard;

	hard.a = 3;
	hard.b = num - 3;
	one_pivot(stack, &hard, num, STACK_A);
	while (hard.b != hard.pb)
	{
		if (hard.p0 <= stack->a[stack->a_len - 1])
			command(RA, stack, &hard);
		else
			command(PB, stack, &hard);
	}
	while (hard.ra > 0)
		hard.ra -= command(RRA, stack, &hard);
	mini_sort(stack, &hard, STACK_A, hard.a);
	mini_sort(stack, &hard, STACK_B, hard.b);
	while (hard.b > 0)
		hard.b -= command(PA, stack, &hard);
}

void	b_large_only(t_stack *stack, size_t num)
{
	size_t	i;
	t_info	hard;

	hard.a = num - 3;
	hard.b = 3;
	i = 0;
	while (i++ < hard.a)
		command(PA, stack, &hard);
	mini_sort(stack, &hard, STACK_A, hard.a);
	mini_sort(stack, &hard, STACK_B, hard.b);
	while (hard.a + hard.b > 0)
	{
		if (hard.a == 0)
			hard.a -= command(PB, stack, &hard);
		else if (hard.b == 0)
			hard.b -= command(RRB, stack, &hard);
		else if (stack->a[stack->a_len - 1] < stack->b[0])
			hard.a -= command(PB, stack, &hard);
		else if (stack->a[stack->a_len - 1] > stack->b[0])
			hard.b -= command(RRB, stack, &hard);
	}
}

void	b_large_another(t_stack *stack, size_t num)
{
	t_info	hard;

	hard.a = num - 3;
	hard.b = 3;
	one_pivot(stack, &hard, num, STACK_B);
	while (hard.a != hard.pa)
	{
		if (stack->b[stack->b_len - 1] <= hard.p0)
			command(RB, stack, &hard);
		else
			command(PA, stack, &hard);
	}
	while (hard.rb > 0)
		hard.rb -= command(RRB, stack, &hard);
	mini_sort(stack, &hard, STACK_A, hard.a);
	mini_sort(stack, &hard, STACK_B, hard.b);
	while (hard.a > 0)
		command(PB, stack, &hard);
}
