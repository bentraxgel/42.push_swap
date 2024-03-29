/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 06:03:10 by seok              #+#    #+#             */
/*   Updated: 2023/06/10 07:12:37 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	command(t_cmd cmd, t_stack *stack, t_info *info)
{
	if (cmd == RA)
		r_command(stack, info, STACK_A, stack->a_len);
	else if (cmd == RB)
		r_command(stack, info, STACK_B, stack->b_len);
	else if (cmd == RRA)
		rr_command(stack, STACK_A, stack->a_len - 1);
	else if (cmd == RRB)
		rr_command(stack, STACK_B, stack->b_len - 1);
	else if (cmd == PA)
		p_command(stack, info, STACK_A);
	else if (cmd == PB)
		p_command(stack, info, STACK_B);
	else if (cmd == SA)
		s_command(stack, STACK_A);
	else if (cmd == SB)
		s_command(stack, STACK_B);
	else
		return (0);
	return (1);
}

void	r_command(t_stack *stack, t_info *info, t_set flag, size_t len)
{
	size_t	va_top;

	if (flag == STACK_A && stack->a_len > 1)
	{
		va_top = stack->a[len - 1];
		while (--len)
			stack->a[len] = stack->a[len - 1];
		stack->a[len] = va_top;
		info->ra++;
	}
	else if (flag == STACK_B && stack->b_len > 1)
	{
		va_top = stack->b[stack->b_len - 1];
		while (--len)
			stack->b[len] = stack->b[len - 1];
		stack->b[len] = va_top;
		info->rb++;
	}
}

void	rr_command(t_stack *stack, t_set flag, size_t top)
{
	size_t	va_bottom;
	size_t	i;

	i = -1;
	if (flag == STACK_A && stack->a_len > 1)
	{
		va_bottom = stack->a[0];
		while (++i < top)
			stack->a[i] = stack->a[i + 1];
		stack->a[i] = va_bottom;
	}
	else if (flag == STACK_B && stack->b_len > 1)
	{
		va_bottom = stack->b[0];
		while (++i < top)
			stack->b[i] = stack->b[i + 1];
		stack->b[i] = va_bottom;
	}
}

void	p_command(t_stack *stack, t_info *info, t_set flag)
{
	size_t	tmp;

	if (flag == STACK_B && stack->a_len > 0)
	{
		tmp = stack->a[stack->a_len - 1];
		stack->a[stack->a_len - 1] = 0;
		stack->a_len--;
		stack->b[stack->b_len] = tmp;
		stack->b_len++;
		info->pb++;
	}
	else if (flag == STACK_A && stack->b_len > 0)
	{
		tmp = stack->b[stack->b_len - 1];
		stack->b[stack->b_len - 1] = 0;
		stack->b_len--;
		stack->a[stack->a_len] = tmp;
		stack->a_len++;
		info->pa++;
	}
}

void	s_command(t_stack *stack, t_set flag)
{
	size_t	tmp;

	if (flag == STACK_A && stack->a_len > 1)
	{
		tmp = stack->a[stack->a_len - 1];
		stack->a[stack->a_len -1] = stack->a[stack->a_len -2];
		stack->a[stack->a_len - 2] = tmp;
	}
	else if (flag == STACK_B && stack->b_len > 1)
	{
		tmp = stack->b[stack->b_len - 1];
		stack->b[stack->b_len -1] = stack->b[stack->b_len -2];
		stack->b[stack->b_len - 2] = tmp;
	}
}
