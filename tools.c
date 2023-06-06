/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quesera <quesera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:05:40 by seok              #+#    #+#             */
/*   Updated: 2023/06/07 03:44:20 by quesera          ###   ########.fr       */
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

int	exception(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
		ret += ft_isdigit(str[i++]);
	return (ret);
}

void	q_sort(int *arr, int left, int right)
{
	int	tmp;
	int	low = left;
	int	high = right;
	int	pivot = arr[(right - left) / 2];

	while (low <= high)
	{
		while (arr[low] <= pivot)
			low++;
		while (arr[high] >= pivot)
			high--;
		if (low < high)
		{
			tmp = arr[low];
			arr[low] = arr[high];
			arr[high] = tmp;
			low++;
			high--;
		}
	}
	if (low < right)
		q_sort(arr, left, high);
	if (high > left)
		q_sort(arr, low, right);
}