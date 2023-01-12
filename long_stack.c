/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:54:25 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/12 08:21:22 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *new_arr, int arr_size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < arr_size - 1)
	{
		j = 0;
		while (j < arr_size - 1 - i)
		{
			if ((new_arr)[j] > (new_arr)[j + 1])
			{
				tmp = (new_arr)[j];
				(new_arr)[j] = (new_arr)[j + 1];
				(new_arr)[j + 1] = tmp;
			}
		j++;
		}
	i++;
	}
}

void	index_group(const int *A, int **sorted, int arr_size)
{
	int	i;
	int	j;
	int	*index_arr;

	index_arr = (int *)malloc(sizeof(int) * arr_size);
	i = 0;
	while (i < arr_size)
	{
		j = 0;
		while (j < arr_size)
		{
			if (A[i] == (*sorted)[j])
			{
				index_arr[i] = j;
				break ;
			}
		j++;
		}
	i++;
	}
	i = -1;
	while (i++ < arr_size - 1)
		(*sorted)[i] = index_arr[i];
	free(*sorted);
	(*sorted) = index_arr;
}

void	binary_string(t_stacks *list, int *arr, int size)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	list->string_a = (char **)malloc(sizeof(char *) * size);
	while (i < size)
	{
		list->string_a[i] = (char *)malloc(sizeof(char) * list->bits + 1);
		num = arr[i];
		j = list->bits - 1;
		while (j >= 0)
		{
			list->string_a[i][j] = (num % 2) + '0';
			num /= 2;
		j--;
		}
		list->string_a[i][list->bits] = '\0';
	i++;
	}
}

void	logic_operations(t_stacks *list)
{
	int	i;
	int	j;
	int	max_len;

	i = 0;
	j = 0;
	max_len = list->arr_size_a;
	while (i < list->bits)
	{
		j = 0;
		while (j < max_len)
		{
			if ((list->string_a[0][list->bits - 1 - i]) == '1')
				ra_string(list);
			else
				pb_string(list);
			j++;
		}
		i++;
		while (list->arr_size_b != 0)
			pa_string(list);
	}	
}

void	go_radix(t_stacks *stack, int n_args)
{
	if (n_args <= 7)
		stack->bits = 3;
	if (n_args > 7 && n_args <= 15)
		stack->bits = 4;
	else if (n_args > 15 && n_args <= 100)
		stack->bits = 7;
	else if (n_args > 100 && n_args <= 500)
		stack->bits = 9;
	binary_string(stack, stack->sorted_arr, stack->arr_size_a);
	logic_operations(stack);
	free_mem(stack->string_a, stack->arr_size_a);
	free_mem(stack->string_b, stack->arr_size_b);
}
