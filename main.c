/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:15 by seok              #+#    #+#             */
/*   Updated: 2023/06/01 19:19:37 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h> //TODO : 지워야징


void	ft_del(t_list *lst)
{
	while (lst != NULL)
	{
		free(lst);
		lst = lst->next;
	}
}

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
	while(str[i])
		ret += ft_isdigit(str[i++]);
	return (ret);
}

char	*join_argv(char **argv)
{
	size_t	i;
	char	*arg;
	char	*space;
	for (int i = 0; argv[i]; i++)
		printf("[%d] : %s\n", i, argv[i]);
	i = 0;
	arg = 0;
	space = " ";
	while (argv[++i])
	{printf("i : %zu\n", i);
		if (exception(argv[i]) != 0)
		{
			arg = ft_strjoin_free(arg, argv[i]);
			arg = ft_strjoin_free(arg, space);
		}
		else
			my_error();
	}
	printf("%s\n", arg);
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
	// free(arg);

	while (word[i]){
		printf("word[%zu] : %s\n", i, word[i]);
		i++;
	}
	stack->total_len = i; //TODO del
	stack->a_len = i;
	stack->b_len = 0;
	stack->a = (int *)malloc(sizeof(int) * (i + 1));
	i = -1;
	while (word[++i])
		stack->a[stack->a_len - i - 1] = ft_atoi_pro(word[i]);
	// while (i-- > 0)
	// 	free(word[i]);
	// free(word);
	if (duplicate_check(stack->a, stack->a_len) == FALSE)
		my_error();
	stack_indexing(stack, 0, stack->a_len);
	stack->b = (int *)ft_calloc(stack->a_len + 1, sizeof(int));
	stack->command = ft_lstnew("start\n");
}

int	main(int argc, char *argv[])
{
	// atexit(leaks); //TODO del
	t_stack	stack;
	// t_info	info;

	if (argc == 1)
		return (0);
	parsing(&stack, argv);
	printf("a_len = %zu\n", stack.a_len);
	for (int i = stack.a_len; i >= 0; i--)
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
	// // if (stack.a)
		// free(stack.a); //왜 얘는 없어도 누수가 안나지? total주소 받아서 그런가.
	// // if (stack.b)
		// free(stack.b);
		// ft_del(stack.command);
	return (0);
}
