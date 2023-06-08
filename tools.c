/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quesera <quesera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:05:40 by seok              #+#    #+#             */
/*   Updated: 2023/06/08 04:08:42 by quesera          ###   ########.fr       */
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
// /*
void	q_sort(int *arr, int left, int right)
{
	int	tmp;
	int	low = left;
	int	high = right;
	int	pivot = arr[(right + left) / 2];

	while (low <= high)
	{
		while (arr[low] < pivot)
			low++;
		while (arr[high] > pivot)
			high--;
		if (low <= high)
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
// */
/*
void q_sort(int arr[], int L, int R) {
      int left = L, right = R;
      int pivot = arr[(L + R) / 2];    // pivot 설정 (가운데) 
      int temp;
      do
      {
        while (arr[left] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
            left++;
        while (arr[right] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
            right--;
        if (left<= right)    // left가 right보다 왼쪽에 있다면 교환 
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            // left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동
            left++;
            right--;
        }
      } while (left<= right);    // left가 right 보다 오른쪽에 있을 때까지 반복 
 
    //  recursion 
    if (L < right)
        q_sort(arr, L, right);    // 왼쪽 배열 재귀적으로 반복 
 
    if (left < R)
        q_sort(arr, left, R);    // 오른쪽 배열 재귀적으로 반복 
}
*/