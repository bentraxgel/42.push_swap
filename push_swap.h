/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:37 by seok              #+#    #+#             */
/*   Updated: 2023/06/09 20:55:55 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdbool.h>
#include <stdio.h> //TODO del

typedef enum e_set
{
	STACK_A = 0,
	STACK_B,
}t_set;

typedef enum e_cmd
{
	RA = 0,
	RB,
	RRA,
	RRB,
	PA,
	PB,
	SA,
	SB,
} t_cmd;

typedef struct s_stack
{
	t_list		*command;
	int			*a;
	int			*b;
	size_t		a_len;
	size_t		b_len;
	size_t		total_len; //TODO del
} t_stack;

typedef struct s_info
{
	int		p0;
	int		p1;
	int		p2;
	size_t	ra;
	size_t	rb;
	size_t	pa;
	size_t	pb;
	size_t	a;
	size_t	b;
} t_info;
void q_sort(int arr[], int L, int R);
//parsing.c
char	*join_argv(char **argv);
void	parsing(t_stack *stack, char **argv);

//main_utill.c
int		my_error();
void	stack_indexing(t_stack *stack, size_t start, size_t len);
int		a_sort_check(int *arr, size_t start, size_t len);
int		b_sort_check(int *arr, size_t start, size_t len);
int		duplicate_check(int *arr, size_t len);

//tools
void	lst_del(t_list *lst);
void	*alloc_guard(size_t typesize, size_t count);
void	q_sort(int *arr, int left, int right);
int		exception(char *str);

//ft_atoi_pro.c
int		ft_isspace_pro(int c);
void	my_check_digit(const char *str);
void	my_check_limit(long long num);
int		ft_atoi_pro(const char *str);

//sort_stack.c
void	a_stack_sort(t_stack *stack, size_t num);
void	b_stack_sort(t_stack *stack, size_t num);

//sort_utill.c
void	two_pivot(t_stack *stack, t_info *info, size_t num, t_set flag);
void	sort_rr(t_stack *stack, t_info *info, size_t num);
int		*ft_subnum(int *arr, size_t start, size_t num);

//hard_sort.c
void	hard_sort(t_stack *stack, t_set flag, size_t num);
void	mini_sort(t_stack *stack, t_info *hard, size_t flag, size_t num);
void	two_sort(t_stack *stack, t_info *hard, t_set flag);
void	one_pivot(t_stack *stack, t_info *hard, size_t num, t_set flag);

//hard_sort2.c
void	a_large_only(t_stack *stack, size_t num);
void	a_large_another(t_stack *stack, size_t num);
void	b_large_only(t_stack *stack, size_t num);
void	b_large_another(t_stack *stack, size_t num);

//hard_three.c
void	a_three_only(t_stack *stack, t_info *info, size_t top);
void	a_three_another(t_stack *stack, t_info *info, size_t top);
void	b_three_only(t_stack *stack, t_info *info, size_t top);
void	b_three_another(t_stack *stack, t_info *info, size_t top);

//sort_a_case.c
void	a_first_case(t_stack *stack, t_info *info);
void	a_second_case(t_stack *stack, t_info *info);
void	a_third_case(t_stack *stack, t_info *info);
void	a_fourth_case(t_stack *stack, t_info *info);
void	a_fifth_case(t_stack *stack, t_info *info);

//sort_b_case.c
void	b_first_case(t_stack *stack, t_info *info);
void	b_second_case(t_stack *stack, t_info *info);
void	b_third_case(t_stack *stack, t_info *info);
void	b_fourth_case(t_stack *stack, t_info *info);
void	b_fifth_case(t_stack *stack, t_info *info);

//command.c
int		command(t_cmd cmd, t_stack *stack, t_info *info);
void	r_command(t_stack *stack, t_info *info, t_set flag, size_t top);
void	rr_command(t_stack *stack, t_set flag, size_t top);
void	p_command(t_stack *stack, t_info *info, t_set flag);
void	s_command(t_stack *stack, t_set flag);

//print.c
t_list	*another_print(t_list *command);
t_list	*r_print(t_list *command);
t_list	*rr_print(t_list *command);
t_list	*s_print(t_list *command);
void	print_command(t_list *command);
#endif
