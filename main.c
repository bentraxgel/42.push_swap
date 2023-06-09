/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:15 by seok              #+#    #+#             */
/*   Updated: 2023/06/09 21:51:33 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h> //TODO : 지워야징

void	ft_leaks()
{
	system("leaks -q push_swap");
}

int	main(int argc, char *argv[])
{
	atexit(ft_leaks); //TODO del
	t_stack	stack;

	if (argc == 1)
		return (0);
	parsing(&stack, argv);
	stack.command = ft_lstnew("start\n");
	a_stack_sort(&stack, stack.a_len);
	print_command(stack.command);
	free(stack.a);
	free(stack.b);
	lst_del(stack.command);
	return (0);
}
