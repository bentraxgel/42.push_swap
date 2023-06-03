/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:44:07 by seok              #+#    #+#             */
/*   Updated: 2023/06/03 19:51:23 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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