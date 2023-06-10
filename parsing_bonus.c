/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:55:10 by seok              #+#    #+#             */
/*   Updated: 2023/06/10 07:42:45 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}
