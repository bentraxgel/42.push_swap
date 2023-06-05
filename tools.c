/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quesera <quesera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:05:40 by seok              #+#    #+#             */
/*   Updated: 2023/06/05 03:17:00 by quesera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_del(t_list *lst)
{
	while (lst != NULL)
	{
		free(lst);
		lst = lst->next;
	}
}

void	*alloc_guard(size_t typesize, size_t count)
{
	void	*ret;

	if (count < 0 || typesize < 0)
		exit(EXIT_FAILURE);
	if (count == 0 || typesize == 0)
	{
		count = 1;
		typesize = 1;
	}
	if (SIZE_MAX / typesize < count)
		exit(EXIT_FAILURE);
	ret = (void *)malloc(count * typesize);
	if (!ret)
		exit(EXIT_FAILURE);
	ft_memset(ret, 0, count * typesize);
	return (ret);
}