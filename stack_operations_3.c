/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:44:27 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/12 08:22:33 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up_string(char **arr, int size)
{
	int		i;
	char	*temp;

	i = 0;
	temp = arr[0];
	while (i < size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[size - 1] = temp;
}

void	rotate_up(int **arr, int *arr_size)
{
	int	*new_arr;
	int	i;

	i = 0;
	new_arr = (int *)malloc(sizeof(int) * (*arr_size));
	if (!new_arr)
		exit(EXIT_FAILURE);
	while (i < (*arr_size - 1))
	{
		new_arr[i] = (*arr)[i + 1];
		i++;
	}
	new_arr[i] = *(arr)[0];
	free(*arr);
	(*arr) = new_arr;
}

void	rotate_down(int **arr, int *arr_size)
{
	int	*new_arr;
	int	i;

	i = 0;
	new_arr = (int *)malloc(sizeof(int) * (*arr_size));
	if (!new_arr)
		exit(EXIT_FAILURE);
	new_arr[0] = (*arr)[(*arr_size - 1)];
	while (i < (*arr_size - 1))
	{
		new_arr[i + 1] = (*arr)[i];
		i++;
	}	
	free(*arr);
	(*arr) = new_arr;
}

int	pop_item(int **arr, int *arr_size)
{
	int	*new_arr;
	int	pop_first;
	int	i;	

	new_arr = (int *)malloc(sizeof(int) * (*arr_size - 1));
	if (!new_arr)
		exit(EXIT_FAILURE);
	pop_first = (*arr)[0];
	i = 0;
	while (i < (*arr_size - 1))
	{
		new_arr[i] = (*arr)[i + 1];
		i++;
	}
	free(*arr);
	*arr = new_arr;
	(*arr_size)--;
	return (pop_first);
}

void	push_item(int **arr, int *arr_size, int value)
{
	int	*new_arr;
	int	i;

	i = 0;
	new_arr = (int *)malloc(sizeof(int) * ((*arr_size) + 1));
	if (!new_arr)
		exit(EXIT_FAILURE);
	new_arr[0] = value;
	while (i < (*arr_size))
	{
		new_arr[i + 1] = (*arr)[i];
		i++;
	}
	free(*arr);
	(*arr) = new_arr;
	(*arr_size)++;
}
