/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 07:39:56 by seok              #+#    #+#             */
/*   Updated: 2023/06/10 07:41:09 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
