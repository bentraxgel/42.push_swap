/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:49:51 by seok              #+#    #+#             */
/*   Updated: 2023/06/10 07:46:39 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_command(char *buf, t_stack *stack, t_info *info)
{
	if (ft_strncmp(buf, "ra\n", 3) == 0)
		command(RA, stack, info);
	else if (ft_strncmp(buf, "rb\n", 3) == 0)
		command(RB, stack, info);
	else if (ft_strncmp(buf, "rr\n", 3) == 0)
	{
		command(RA, stack, info);
		command(RB, stack, info);
	}
	else if (ft_strncmp(buf, "rra\n", 4) == 0)
		command(RRA, stack, info);
	else if (ft_strncmp(buf, "rrb\n", 4) == 0)
		command(RRB, stack, info);
	else if (ft_strncmp(buf, "rrr\n", 4) == 0)
	{
		command(RRA, stack, info);
		command(RRB, stack, info);
	}
	else
		check_command2(buf, stack, info);
}

void	check_command2(char *buf, t_stack *stack, t_info *info)
{
	if (ft_strncmp(buf, "pa\n", 3) == 0)
		command(PA, stack, info);
	else if (ft_strncmp(buf, "pb\n", 3) == 0)
		command(PB, stack, info);
	else if (ft_strncmp(buf, "sa\n", 3) == 0)
		command(SA, stack, info);
	else if (ft_strncmp(buf, "sb\n", 3) == 0)
		command(SB, stack, info);
	else if (ft_strncmp(buf, "ss\n", 3) == 0)
	{
		command(SA, stack, info);
		command(SB, stack, info);
	}
	else
	{
		free(stack->a);
		free(stack->b);
		free(buf);
		my_error();
	}
}

void	main_else(t_stack *stack)
{
	if (a_sort_check(stack->a, 0, stack->a_len) == true \
		&& stack->b_len == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	free(stack->a);
	free(stack->b);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_stack	stack;
	t_info	info;
	char	*str;

	if (argc == 1)
		return (0);
	parsing(&stack, argv);
	while (1)
	{
		str = get_next_line(0);
		if (ft_strlen(str) > 0)
		{
			check_command(str, &stack, &info);
			free(str);
		}
		else
			main_else(&stack);
	}
	return (0);
}
