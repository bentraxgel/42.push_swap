/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 03:18:32 by quesera           #+#    #+#             */
/*   Updated: 2023/06/10 07:39:55 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
