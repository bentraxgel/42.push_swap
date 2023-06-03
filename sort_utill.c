/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:45:25 by quesera           #+#    #+#             */
/*   Updated: 2023/06/03 22:29:33 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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