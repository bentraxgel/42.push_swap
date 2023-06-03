/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quesera <quesera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:06:06 by seok              #+#    #+#             */
/*   Updated: 2023/06/02 22:21:05 by quesera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	print_command(t_list *command)
{
	command = command->next; //"start\n"없애는 코드
	while (command)
	{
		if (ft_strncmp(command->content, "ra\n", 3) == 0 \
			|| ft_strncmp(command->content, "rb\n", 3 == 0))
		{
			command = r_print(command);
		}
		else if (ft_strncmp(command->content, "rra\n", 3) == 0 \
				|| ft_strncmp(command->content, "rrb\n", 3 == 0))
		{
			command = rr_print(command);
		}
		else if (ft_strncmp(command->content, "sa\n", 3) == 0 \
				|| ft_strncmp(command->content, "sb\n", 3 == 0))
		{
			command = s_print(command);
		}
		else
			ft_putstr_fd(command->content, STDOUT_FILENO);
		command = command->next;
	}
}

t_list	*r_print(t_list *command)
{
	t_list	*ret;

	ret = command;
	if (command->next != 0)
	{
		if (ft_strncmp(command->content, "ra\n", 3) == 0 \
			&& ft_strncmp(command->next->content, "rb\n", 3 == 0))
		{
			ft_putstr_fd("rr\n", STDOUT_FILENO);
			ret = command->next;
		}
		else if (ft_strncmp(command->content, "rb\n", 3) == 0 \
				&& ft_strncmp(command->next->content, "ra\n", 3 == 0))
		{
			ft_putstr_fd("rr\n", STDOUT_FILENO);
			ret = command->next;
		}
		else
			ft_putstr_fd(command->content, STDOUT_FILENO);
	}
	else
		ft_putstr_fd(command->content, STDOUT_FILENO);
	return (ret);
}

t_list	*rr_print(t_list *command)
{
	t_list	*ret;

	ret = command;
	if (command->next != 0)
	{
		if (ft_strncmp(command->content, "rra\n", 3) == 0 \
			&& ft_strncmp(command->next->content, "rrb\n", 3 == 0))
		{
			ft_putstr_fd("rrr\n", STDOUT_FILENO);
			ret = command->next;
		}
		else if (ft_strncmp(command->content, "rrb\n", 3) == 0 \
				&& ft_strncmp(command->next->content, "rra\n", 3 == 0))
		{
			ft_putstr_fd("rrr\n", STDOUT_FILENO);
			ret = command->next;
		}
		else
			ft_putstr_fd(command->content, STDOUT_FILENO);
	}
	else
		ft_putstr_fd(command->content, STDOUT_FILENO);
	return (ret);
}

t_list	*s_print(t_list *command)
{
	t_list	*ret;

	ret = command;
	if (command->next != 0)
	{
		if (ft_strncmp(command->content, "sa\n", 3) == 0 \
			&& ft_strncmp(command->next->content, "sb\n", 3 == 0))
		{
			ft_putstr_fd("ss\n", STDOUT_FILENO);
			ret = command->next;
		}
		else if (ft_strncmp(command->content, "sb\n", 3) == 0 \
				&& ft_strncmp(command->next->content, "sa\n", 3 == 0))
		{
			ft_putstr_fd("ss\n", STDOUT_FILENO);
			ret = command->next;
		}
		else
			ft_putstr_fd(command->content, STDOUT_FILENO);
	}
	else
		ft_putstr_fd(command->content, STDOUT_FILENO);
	return (ret);
}
