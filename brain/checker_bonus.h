/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:51:02 by seok              #+#    #+#             */
/*   Updated: 2023/06/09 23:26:11 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CHECKER_H
# define CHECKER_H

#include "../push_swap.h"

//command_bonus.c
int	command(t_cmd cmd, t_stack *stack, t_info *info);
void	r_command(t_stack *stack, t_info *info, t_set flag, size_t len);
void	rr_command(t_stack *stack, t_set flag, size_t top);
void	p_command(t_stack *stack, t_info *info, t_set flag);
void	s_command(t_stack *stack, t_set flag);

//ft_atoi_pro_bonus.c
int	ft_isspace_pro(int c);
void	my_check_digit(const char *str);
void	my_check_limit(long long num);
int	ft_atoi_pro(const char *str);

//main_bonus.c
void	check_command(char *buf, t_stack *stack, t_info *info);
void	free_exit(t_stack *stack);

//main_utill_bonus.c
int	my_error(void);
void	stack_indexing(t_stack *stack, size_t start, size_t len);
int	a_sort_check(int *arr, size_t start, size_t len);
int	b_sort_check(int *arr, size_t start, size_t len);
int	duplicate_check(int *arr, size_t len);

//parsing_bonus.c
char	*join_argv(char **argv);
void	parsing(t_stack *stack, char **argv);

//tools_bonus.c
void	lst_del(t_list *lst);
void	*alloc_guard(size_t typesize, size_t count);
int	exception(char *str);
void q_sort(int arr[], int L, int R);

# endif