/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:58:14 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/19 23:36:22 by ivda-cru         ###   ########.fr       */
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

void pa(t_stacks *stack)
{
	int popped;
	
	if (stack->B.arr_sizeB != 0)
	{
		popped = pop_item(&(stack->B.arrB), &(stack->B.arr_sizeB));
		push_item(&(stack->A.arrA), &(stack->A.arr_sizeA), popped);
		ft_printf("pa\n");	
	}
}

void pb(t_stacks *stack)
{
	int popped;

	if (stack->A.arr_sizeA != 0)
	{
		popped = pop_item(&(stack->A.arrA), &(stack->A.arr_sizeA));
		push_item(&(stack->B.arrB), &(stack->B.arr_sizeB), popped);
		ft_printf("pb\n");	
	}

}
