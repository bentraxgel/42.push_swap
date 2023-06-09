/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:49:51 by seok              #+#    #+#             */
/*   Updated: 2023/06/10 06:23:43 by seok             ###   ########.fr       */
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
		free(buf);
		my_error();
	}
	// free(buf);
}

void	free_exit(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	// lst_del(stack->command);
	exit(EXIT_SUCCESS);
}

void	leaks()
{
	system("leaks --list checker");
}

#include <stdio.h>

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	sstart;
	size_t	i;
	size_t	s_len;

	i = 0;
	sstart = (size_t)start;
	s_len = ft_strlen(s);
	if (s_len <= sstart)
		return (NULL);
	if (s_len - start <= len)
		str = (char *)malloc(sizeof(char) * (s_len - start + 1));
	if (s_len - start > len)
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s[sstart + i] && i < len)
	{
		str[i] = s[sstart + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	main(int argc, char *argv[])
{
	atexit(leaks);
	// t_stack	stack;
	// t_stack *stack;
	//stack = (t_stack *)malloc()
	// stack.command = (t_list *)malloc();
	// stack.command[0] = 'r'
	// memset(&stack);
	// another func == stack->a
	// t_info	info;
	// char	buf[10];
	char	*str;

	if (argc == 1)
		return (0);
	// parsing(&stack, argv);
	// stack.command = ft_lstnew("start\n");
	(void)argv;
	while (1)
	{
		// ft_memset(buf, 0, 10);
		str = get_next_line(0);
		if (ft_strlen(str) == 0)
		{
			free(str);
			return (0);
		}
		printf("str %s\n", str);
		free(str);
		// if (ft_strlen(str) > 0)
		// {
		// 	check_command(str, &stack, &info);
		// 	free(str);
		// } 
		// else
		// {
		// 	if (a_sort_check(stack.a, 0, stack.a_len) == true && stack.b_len == 0)
		// 		ft_putstr_fd("OK\n", STDOUT_FILENO);
		// 	else
		// 		ft_putstr_fd("KO\n", STDOUT_FILENO);
		// 	free_exit(&stack);
		// }
		// free(str);
	}
	return (0);
}

t_lst	*my_lst_make(t_lst **head)
{
	(*head) = malloc(sizeof(t_lst));
	if (!(*head))
		return (NULL);
	(*head)->fd = -1;
	(*head)->next = NULL;
	return (*head);
}

void	my_lst_free(t_lst *find, t_lst *head)
{
	t_lst	*temp;

	temp = head;
	while (temp->next != NULL && temp->next != find)
		temp = temp->next;
	if (head == NULL)
		free(head);
	if (find->save != NULL)
		free(find->save);
	temp->next = find->next;
	find->next = NULL;
	free(find);
}

t_lst	*my_lst_find(t_lst **head, int f_fd)
{
	t_lst	*temp;
	t_lst	*remember;

	if (*head == NULL)
		*head = my_lst_make(head);
	temp = *head;
	while (temp)
	{
		if (temp->fd == f_fd)
			return (temp);
		temp = temp->next;
	}
	remember = *head;
	while ((*head)->next)
		(*head) = (*head)->next;
	temp = malloc(sizeof(t_lst));
	if (!temp)
		return (NULL);
	(*head)->next = temp;
	temp->save = NULL;
	temp->next = NULL;
	temp->fd = f_fd;
	*head = remember;
	return (temp);
}

int	my_save_buf(t_lst *find, char **ret, int check)
{
	char	*temp;
	int		idx;

	idx = BUFFER_SIZE + 1;
	while (idx--)
		find->buf[idx] = 0;
	check = 0;
	check = read(find->fd, find->buf, BUFFER_SIZE);
	find->save = ft_strjoin(find->save, find->buf);
	idx = -1;
	while (find->save[++idx])
	{
		if (find->save[idx] == '\n')
		{
			*ret = gnl_substr(find->save, 0, idx + 1);
			temp = gnl_substr(find->save, idx + 1, \
							ft_strlen(find->save) - (idx + 1));
			free(find->save);
			find->save = temp;
			return (1);
		}
	}
	return (check);
}

char	*my_save_check(int fd, t_lst **head)
{
	char		*ret;
	int			check;
	t_lst		*find;

	ret = 0;
	check = 0;
	find = my_lst_find(head, fd);
	while (ret == 0)
	{
		check = my_save_buf(find, &ret, check);
		if (check < 0 || (check == 0 && find->save == 0))
		{
			my_lst_free(find, *head);
			return (NULL);
		}
		else if (check == 0 && find->save != 0)
		{
			ret = gnl_substr(find->save, 0, ft_strlen(find->save));
			my_lst_free(find, *head);
			return (ret);
		}
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_lst	*head;
	t_lst			*find;
	char			*ret;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		find = head;
		while (find)
		{
			if (find->fd == fd)
			{
				my_lst_free(find, head);
				return (NULL);
			}
			find = find->next;
		}
		return (0);
	}
	ret = my_save_check(fd, &head);
	if (head->fd == -1 && head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	return (ret);
}
