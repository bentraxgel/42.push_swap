/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quesera <quesera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:15 by seok              #+#    #+#             */
/*   Updated: 2023/06/05 03:17:00 by quesera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h> //TODO : 지워야징

void	leaks()
{
	system("leaks -q a.out");
}

int	exception(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
		ret += ft_isdigit(str[i++]);
	return (ret);
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
//파싱 잘 되는건 확인 완료!
int	main(int argc, char *argv[])
{
	atexit(leaks); //TODO del
	t_stack	stack;

	if (argc == 1)
		return (0);
	parsing(&stack, argv);
	printf("a_len = %zu\n", stack.a_len);
	for (int i = stack.a_len - 1; i >= 0; i--)
		printf("a[%d] : %d\n", i, stack.a[i]);
/*
	이제 여기서 sort해야함......!!
*/
	// save_pivot(&stack, &info, STACK_A, stack.a_len);
	// a_stack_sort(&stack, stack.a_len, &info);
	// // func(stack.command);
	// for (int i = stack.total_len - 1; i >= 0; i--)
	// 	printf("a[%d] : %d\tb[%d] : %d\n", i, stack.a[i], i, stack.b[i]);
	// printf("a_len : %zu\tb_len : %zu\n", stack.a_len, stack.b_len);
	
	// /* 명령어 출력해야지 */
	// print_command(stack.command);
	free(stack.a);
	free(stack.b);
	lst_del(stack.command);
	return (0);
}
