/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:58:08 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/16 17:02:44 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pop_item(int **arr, int *arr_size)
{
	int *new_arr;
	int pop_first;
	int i;

	if (*(arr_size) != 0)
	{
		new_arr = (int *)malloc(sizeof(int) * (*arr_size - 1));
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
	else
		exit(0);
}

void push_item(int **arr, int *arr_size, int value)
{
	int *new_arr;
	int i;

	i = 0;
	new_arr = (int *)malloc(sizeof(int) * ((*arr_size) + 1));
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

void push_b_to_a(t_stacks *stack)
{
	int popped;

	popped = pop_item(&(stack->B.arrB), &(stack->B.arr_sizeB));
	push_item(&(stack->A.arrA), &(stack->A.arr_sizeA), popped);
}

void push_a_to_b(t_stacks *stack)
{
	int popped;

	popped = pop_item(&(stack->A.arrA), &(stack->A.arr_sizeA));
	push_item(&(stack->B.arrB), &(stack->B.arr_sizeB), popped);
}

void	sa_swap(t_stacks *swap)
{
	int tmp;

	tmp = 0;	
	if (swap->A.arr_sizeA > 1)	
	{
		tmp = swap->A.arrA[0];
		swap->A.arrA[0] = swap->A.arrA[1];
		swap->A.arrA[1] = tmp;		
	}
}

void	sb_swap(t_stacks *swap)
{
	int tmp;

	tmp = 0;
	if (swap->B.arr_sizeB > 1)	
	{
		tmp = swap->B.arrB[swap->B.arr_sizeB - 1];
		swap->B.arrB[swap->B.arr_sizeB - 1] = swap->B.arrB[swap->B.arr_sizeB - 2];
		swap->B.arrB[swap->B.arr_sizeB - 2] = tmp;		
	}
}

void	ss_swap(t_stacks *swap)
{
	sa_swap(swap);
	sb_swap(swap);
}