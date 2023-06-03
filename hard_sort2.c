/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:33:14 by seok              #+#    #+#             */
/*   Updated: 2023/06/03 23:16:44 by seok             ###   ########.fr       */
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
	while(i++ < hard.b)
		command(PB, stack, &hard);
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
	while (hard.b++ < i)
		command(PA, stack, &hard);
}

void	a_large_another(t_stack *stack, size_t num)
{
	t_info	hard;
	size_t	i;

	hard.a = 3;
	hard.b = num - 3;
	i = 0;
	one_pivot(stack, &hard, num, STACK_A);
	while (hard.b != hard.pb) //TODO *여기서부터 시작! 이거 조건 다시 생각하고 확인하기!
	{
		if (hard.p0 <= stack.a[stack.a_len - 1])
			command(PB, stack, hard);
	}
	
}