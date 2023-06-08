/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_utill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:14:53 by seok              #+#    #+#             */
/*   Updated: 2023/06/08 19:48:04 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sort(t_stack *stack, t_set flag, t_info *info)
{
	if (flag == STACK_A)
	{
		if (stack->a[stack->a_len - 1] < stack->a[stack->a_len - 2])
			return ;
		else if (stack->a[stack->a_len - 1] > stack->a[stack->a_len - 2])
			command(SA, stack, info);
	}
	else if (flag == STACK_B)
	{
		if (stack->b[stack->b_len - 1] > stack->b[stack->b_len - 2])
			return ;
		else if (stack->b[stack->b_len - 1] < stack->b[stack->b_len - 2])
			command(SB, stack, info);
	}
}

void	hard_a_only(t_stack *stack, t_info *info, size_t num)
{
	printf("hard_a_only\n");
	int	i;

	info->a = 3;
	info->b = num - 3;
	i = 0;
	while (i++ < info->b){
		printf("i : %d  b : %d\n", i, info->b);
		command(PB, stack, info);
	}
	mini_sort(stack, info, info->a, STACK_A);
	mini_sort(stack, info, info->b, STACK_B);
	while (info->a + info->b)
	{
		if (info->a == 0){
			printf("<<1>>\n");
			info->b -= command(PA, stack, info);
		}
		else if (info->b == 0)
			info->a -= command(RRA, stack, info);
		else if (stack->a[0] > stack->b[stack->b_len - 1])
			info->a -= command(RRA, stack, info);
		else if (stack->a[0] < stack->b[stack->b_len - 1]){
			printf("<<2>>\n");
			info->b -= command(PA, stack, info);
		}
	}
	// while (i-- > 0){
	// 	printf("<<3>>\n");
	// 	command(PA, stack, info);
	// }
}

void	hard_a_another(t_stack *stack, t_info *info, size_t num)
{
	printf("error hard_a_another\n");
	mini_pivot(stack, info, STACK_A, num);
	// info->b = num - 3;
	// while (info->a < 3 && info->b > 0)
	while (info->b < num - 3 && info->a + info->b < num)
	{
		if (stack->a[stack->a_len - 1] < info->p0)
			info->b += command(PB, stack, info);
		else
			info->a += command(RA, stack, info);
	}
	while (info->a > 0)
		info->a -= command(RRA, stack, info);
	mini_sort(stack, info, 3, STACK_A);
	mini_sort(stack, info, num - 3, STACK_B);
	while (info->pb > 0)
		info->pb -= command(PA, stack, info);
}

void	hard_b_only(t_stack *stack, t_info *info, size_t num)
{
	printf("hard_b_only\n");
	int	i;

	info->a = num - 3;
	info->b = 3;
	i = 0;

	while (i++ < info->a)
		command(PA, stack, info);
		
		printf("\nmini\n");
		printf("pa : %d\tpb : %d\n", info->pa, info->pb);
		printf("ra : %d\trb : %d\n", info->ra, info->rb);
	
	mini_sort(stack, info, info->a, STACK_A);
	mini_sort(stack, info, info->b, STACK_B);
	
		for (int i = stack->total_len; i >= 0; i--)
			printf("a[%d] : %d\tv[%d] : %d\n", i, stack->a[i], i, stack->b[i]);
	
	//TODO THAT IS PROBLEM
	if (a_sort_check(stack->a, stack->a_len) == true && b_sort_check(stack->b, stack->b_len) == true)
	{
		printf("IN?");
		while (info->b-- != 0){
			printf("in  b : %d\n", info->b);
			command(PA, stack, info);
		}
		printf("check-> return\n");
		return ;
	}
	while (info->a + info->b)
	{
		printf("info  a : %d\tb : %d\n", info->a, info->b);
		if (info->b == 0)
			{
				printf("<<1>>\n");
				info->a -= command(PB, stack, info);
			}
		else if (info->a == 0)
			info->b -= command(RRB, stack, info);
		else if (stack->b[0] > stack->a[stack->a_len - 1])
			{
				printf("<<2>>\n");
				info->a -= command(PB, stack, info);
			}
		else if (stack->b[0] < stack->a[stack->a_len - 1])
			info->b -= command(RRB, stack, info);
	}
	// while (i-- > 0){
	// 	printf("<<3>>\n");
	// 	command(PB, stack, info);
	// }
}

void	hard_b_another(t_stack *stack, t_info *info, size_t num)
{
	printf("hard_b_another\n");
	mini_pivot(stack, info, STACK_B, num);
	// info->a = num - 3;
	// while (info->a > 0 && info->b < 3)
	while (info->a < num - 3 && info->a + info->b < num)
	{
		if (stack->b[stack->b_len - 1] >= info->p0)
			info->a += command(PA, stack, info);
		else
			info->b += command(RB, stack, info);
	}
	while (info->b > 0)
		info->b -= command(RRB, stack, info);
	mini_sort(stack, info, num - 3, STACK_A);
	mini_sort(stack, info, 3, STACK_B);
	while (info->pa > 0)
		info->pa -= command(PB, stack, info);
}
