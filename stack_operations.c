/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 07:28:11 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/06 00:56:20 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *swap)
{
	int tmp;

	tmp = 0;	
	tmp = swap->sorted_arr[0];
	swap->sorted_arr[0] = swap->sorted_arr[1];
	swap->sorted_arr[1] = tmp;
	ft_printf("sa\n");
}

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

void ra(t_stacks *list)
{	
	if (list->arr_sizeA > 1)
	{
		//rotate_up(&(A->arrA), &(A->arr_sizeA));
		rotate_up(&(list->sorted_arr), &(list->arr_sizeA));
		ft_printf("ra\n");		
	}
}

void rra(t_stacks *list)
{
	if (list->arr_sizeA > 1)
	{
		rotate_down(&(list->sorted_arr), &(list->arr_sizeA));
		ft_printf("rra\n");		
	}
}

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

	if (stack->arr_sizeB != 0)
	{
		popped = pop_item(&(stack->arrB), &(stack->arr_sizeB));
		push_item(&(stack->sorted_arr), &(stack->arr_sizeA), popped);
		ft_printf("pa\n");	
	}
}

void pb(t_stacks *stack)
{
	int popped;
	
	 if (stack->arr_sizeA != 0)
	{
		popped = pop_item(&(stack->sorted_arr), &(stack->arr_sizeA));
		push_item(&(stack->arrB), &(stack->arr_sizeB), popped);
		ft_printf("pb\n");	
	}

}