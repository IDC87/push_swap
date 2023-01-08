/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/08 06:26:57 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_mem(char **list, int rows)
{
	int i;
	i = 0;
	while (i < rows)  
    {
        free(list[i]);
		i++;
    }
    free(list);   
}

void short_solve(t_stacks *S)
{	
	if (S->sorted_arr[0] > S->sorted_arr[1])
	{
		if (S->arr_sizeA == 2)
		{
			sa(S);
			return;
		}
		if (S->sorted_arr[1] > S->sorted_arr[2])
		{
			ra(S);
			sa(S);
		}
		else if (S->sorted_arr[0] > S->sorted_arr[2])
			ra(S);
		else
			sa(S);	
	}
	else if (S->sorted_arr[1] > S->sorted_arr[2])
	{
		if (S->sorted_arr[0] > S->sorted_arr[2])
			rra(S);
		else
		{
			sa(S);
			ra(S);				
		}		
	}	
}

void check_arguments(char **args, int arg_count)
{
	int i;

	i = 0;
	if (arg_count == 1)
		exit(0);
	while (i < arg_count - 1)
	{
		if (!ft_isdigit_negative(args[1 + i][0]))
			error();
		if (!check_int_limits(ft_atoi(args[1 + i])))
			error();		
		i++;		
	}
	if (is_duplicated(arg_count, args))
		error();
	if(is_sorted_args(arg_count, args) == 1)
		exit(0);
}

void initiate_variables(t_stacks *stack, char **args, int arg_count)
{
	int i;

	i = 0;	
	stack->arr_sizeA = arg_count - 1;
	stack->arr_sizeB = 0;
	stack->arrA = (int *)malloc(sizeof(int) * stack->arr_sizeA);
	stack->sorted_arr = (int *)malloc(sizeof(int) * stack->arr_sizeA);
	if (stack->sorted_arr == NULL || stack->arrA == NULL)
		return;	
	stack->arrB = NULL;	
	stack->stringA = NULL;
	stack->stringB = NULL;
	stack->n_iterarions = 0;
	stack->bits = 9;	
	while(i < stack->arr_sizeA)
	{		
		stack->sorted_arr[i] = ft_atoi(args[i + 1]);
		stack->arrA[i] = ft_atoi(args[i + 1]);		
		i++;				
	}
}

int main	(int argc, char **argv)
{
	t_stacks stack;
		
	check_arguments(argv, argc);	
	initiate_variables(&stack, argv, argc);	
	bubble_sort(stack.sorted_arr, stack.arr_sizeA);
	index_group(stack.arrA, &stack.sorted_arr, stack.arr_sizeA);	
	if (argc - 1 >= 2 && argc - 1 <= 3)
		short_solve(&stack);
	else if (argc - 1 == 4 || argc - 1 == 5)
		medium_solve(&stack);
	else if (argc - 1 > 5)
		go_radix(&stack, argc - 1);	
	free(stack.arrA);
	free(stack.arrB);
	free(stack.sorted_arr);	
	return (0);
}