/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:49:51 by seok              #+#    #+#             */
/*   Updated: 2023/06/09 23:23:56 by seok             ###   ########.fr       */
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
	else if (ft_strncmp(buf, "pa\n", 3) == 0)
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
		my_error();
	}
}

void	free_exit(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	exit(EXIT_SUCCESS);
}

void	leaks()
{
	system("leaks -q a.out");
}

int	main(int argc, char *argv[])
{
	atexit(leaks);
	t_stack	stack;
	t_info	info;
	char	buf[10];

	if (argc == 1)
		return (0);
	parsing(&stack, argv);
	while (1)
	{
		if (read(0, buf, 10) > 0)
			check_command(buf, &stack, &info);
		else
		{
			if (a_sort_check(stack.a, 0, stack.a_len) == true && stack.b_len == 0)
				ft_putstr_fd("OK\n", STDOUT_FILENO);
			else
				ft_putstr_fd("KO\n", STDOUT_FILENO);
			free_exit(&stack);
		}
	}
	return (0);
}