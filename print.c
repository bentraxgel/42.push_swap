/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:06:06 by seok              #+#    #+#             */
/*   Updated: 2023/06/08 22:50:24 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_command(t_list *command)
{
	command = command->next;
	while (command)
	{
		if (ft_strncmp((char *)command->content, "ra\n", 4) == 0 \
			|| ft_strncmp((char *)command->content, "rb\n", 4 == 0))
			command = r_print(command);
		else if (ft_strncmp((char *)command->content, "rra\n", 4) == 0 \
				|| ft_strncmp((char *)command->content, "rrb\n", 4 == 0))
			command = rr_print(command);
		else if (ft_strncmp((char *)command->content, "sa\n", 4) == 0 \
				|| ft_strncmp((char *)command->content, "sb\n", 4 == 0))
			command = s_print(command);
		else
			command = another_print(command);
	}
}

t_list	*another_print(t_list *command)
{
	ft_putstr_fd((char *)command->content, STDOUT_FILENO);
	return (command->next);
}

t_list	*r_print(t_list *command)
{
	if (command->next != 0)
	{
		if (ft_strncmp((char *)command->content, "ra\n", 3) == 0 \
			&& ft_strncmp((char *)command->next->content, "rb\n", 3) == 0)
		{
			ft_putstr_fd("rr\n", STDOUT_FILENO);
			command = command->next;
		}
		else if (ft_strncmp((char *)command->content, "rb\n", 3) == 0 \
				&& ft_strncmp((char *)command->next->content, "ra\n", 3) == 0)
		{
			ft_putstr_fd("rr\n", STDOUT_FILENO);
			command = command->next;
		}
		else
			ft_putstr_fd((char *)command->content, STDOUT_FILENO);
	}
	else
		ft_putstr_fd((char *)command->content, STDOUT_FILENO);
	return (command->next);
}

t_list	*rr_print(t_list *command)
{
	if (command->next != 0)
	{
		if (ft_strncmp(command->content, "rra\n", 4) == 0 \
			&& ft_strncmp(command->next->content, "rrb\n", 4)== 0)
		{
			ft_putstr_fd("rrr\n", STDOUT_FILENO);
			command = command->next;
		}
		else if (ft_strncmp((char *)command->content, "rrb\n", 4) == 0 \
				&& ft_strncmp((char *)command->next->content, "rra\n", 4) == 0)
		{
			ft_putstr_fd("rrr\n", STDOUT_FILENO);
			command = command->next;
		}
		else
			ft_putstr_fd((char *)command->content, STDOUT_FILENO);
	}
	else
		ft_putstr_fd((char *)command->content, STDOUT_FILENO);
	return (command->next);
}

t_list	*s_print(t_list *command)
{
	if (command->next != 0)
	{
		if (ft_strncmp((char *)command->content, "sa\n", 3) == 0 \
			&& ft_strncmp((char *)command->next->content, "sb\n", 3) == 0)
		{
			ft_putstr_fd("ss\n", STDOUT_FILENO);
			command = command->next;
		}
		else if (ft_strncmp((char *)command->content, "sb\n", 3) == 0 \
				&& ft_strncmp((char *)command->next->content, "sa\n", 3) == 0)
		{
			ft_putstr_fd("ss\n", STDOUT_FILENO);
			command = command->next;
		}
		else
			ft_putstr_fd((char *)command->content, STDOUT_FILENO);
	}
	else
		ft_putstr_fd((char *)command->content, STDOUT_FILENO);
	return (command->next);
}
