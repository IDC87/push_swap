/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:15:27 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/18 17:32:34 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_up(int **arr, int *arr_size)
{    
    int *new_arr;
	int i;

	i = 0;	
	new_arr = (int *)malloc(sizeof(int) * (*arr_size));
	while (i < (*arr_size - 1))
	{
		new_arr[i] = (*arr)[i + 1];		
		i++;		
	}
	new_arr[i] = *(arr)[0];
	free(*arr);
	(*arr) = new_arr;
}

void rotate_down(int **arr, int *arr_size)
{
	int *new_arr;
	int i;

	i = 0;
	new_arr = (int *)malloc(sizeof(int) * (*arr_size));
	new_arr[0] = (*arr)[(*arr_size - 1)];
	while (i < (*arr_size - 1))
	{
		new_arr[i + 1] = (*arr)[i];
		i++;
	}	
	free(*arr);
	(*arr) = new_arr;
}

void ra(stackA *A)
{
	rotate_up(&(A->arrA), &(A->arr_sizeA));
}

void rb(stackB *B)
{
	rotate_up(&(B->arrB), &(B->arr_sizeB));
}

void rr(stackA *A, stackB *B)
{
	rotate_up(&(A->arrA), &(A->arr_sizeA));
	rotate_up(&(B->arrB), &(B->arr_sizeB));
}