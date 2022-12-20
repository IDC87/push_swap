/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:15:27 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/20 23:41:51 by ivda-cru         ###   ########.fr       */
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
	if (A->arr_sizeA > 1)
	{
		rotate_up(&(A->arrA), &(A->arr_sizeA));
		ft_printf("ra\n");		
	}
}

void rb(stackB *B)
{
	if (B->arr_sizeB > 1)
	{
		rotate_up(&(B->arrB), &(B->arr_sizeB));
		ft_printf("rb\n");		
	}
}

void rr(stackA *A, stackB *B)
{
	if (A->arr_sizeA > 1)
		rotate_up(&(A->arrA), &(A->arr_sizeA));
	if (B->arr_sizeB > 1)
		rotate_up(&(B->arrB), &(B->arr_sizeB));
	ft_printf("rr\n");
}