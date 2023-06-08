/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:15 by seok              #+#    #+#             */
/*   Updated: 2023/06/08 22:50:25 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h> //TODO : 지워야징

void	ft_leaks()
{
	system("leaks --list push_swap");
}

char	*join_argv(char **argv)
{
	size_t	i;
	char	*arg;
	char	*space;

	i = 0;
	arg = 0;
	space = " ";
	while (argv[++i])
	{
		if (exception(argv[i]) != 0)
		{
			arg = ft_strjoin_free(arg, argv[i]);
			arg = ft_strjoin_free(arg, space);
		}
		else
			my_error();
	}
	return (arg);
}

void	parsing(t_stack *stack, char **argv)
{
	size_t	i;
	char	*arg;
	char	**word;

	i = 0;
	arg = join_argv(argv);
	printf("%s\n", arg);
	word = ft_split(arg, ' ');
	free(arg);
	while (word[i])
		i++;
	stack->a_len = i;
	stack->total_len = i; //TODO DEL
	stack->b_len = 0;
	stack->a = (int *)alloc_guard(sizeof(int), stack->a_len);
	i = -1;
	while (word[++i])
		stack->a[stack->a_len - i - 1] = ft_atoi_pro(word[i]);
	while (i-- > 0)
		free(word[i]);
	free(word);
	if (duplicate_check(stack->a, stack->a_len) == false)
		my_error();
	stack_indexing(stack, 0, stack->a_len);
	stack->b = (int *)alloc_guard(sizeof(int), stack->a_len);
	stack->command = ft_lstnew("start\n");
}

int	main(int argc, char *argv[])
{
	atexit(ft_leaks); //TODO del
	t_stack	stack;

	if (argc == 1)
		return (0);
	parsing(&stack, argv);
	a_stack_sort(&stack, stack.a_len);
	print_command(stack.command);
	free(stack.a);
	free(stack.b);
	lst_del(stack.command);
	return (0);
}
