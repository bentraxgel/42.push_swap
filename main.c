/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 08:07:27 by seok              #+#    #+#             */
/*   Updated: 2023/06/10 12:36:45 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
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
