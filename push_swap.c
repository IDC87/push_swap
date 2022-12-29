/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/29 21:59:09 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

//https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e



void brute_force(t_stacks *stack)
{
	static int operations_counter;
		
	while (!is_sorted(stack->A.arrA, stack->A.arr_sizeA, stack->B.arr_sizeB))
	{		
		
		if ((rand() % 11 + 1) == 1)
			sa(stack, 0);		
		if ((rand() % 11 + 1) == 2)
			sb(stack, 0);
		if ((rand() % 11 + 1) == 3)
			ss(stack);
		if ((rand() % 11 + 1) == 4)
			pa(stack);
		if ((rand() % 11 + 1) == 5)
			pb(stack);
		if ((rand() % 11 + 1) == 6)
			ra(&stack->A);
		if ((rand() % 11 + 1) == 7)
			rb(&stack->B);
		if ((rand() % 11 + 1) == 8)
			rr(&stack->A, &stack->B);
		if ((rand() % 11 + 1) == 9)
			rra(&stack->A);
		if ((rand() % 11 + 1) == 10)
			rrb(&stack->B);
		if ((rand() % 11 + 1) == 11)
			rrr(&stack->A, &stack->B);
		
		operations_counter++;
		
	}
	ft_printf("\nNumber of operations: %d\n", operations_counter);	
}

void group_numbers(int *new_arr, int arr_size) // novo nome sort_array
{
	int i;
	int j;
	int tmp;

	i = 0;	
	while (i < arr_size - 1)
		{
			j = 0;
			while(j < arr_size - 1 - i)
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

void index_group(const int *A, int **sorted, int arr_size)
{
	int i;
	int j;
	int *index_arr;
	
	index_arr = (int *)malloc(sizeof(int) * arr_size);
	i = 0;
	while (i < arr_size)
	{
		j = 0;
		while (j < arr_size )
		{
			if (A[i] ==  (*sorted)[j])
			{
				index_arr[i] = j;
				break;
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

void binary_convert(int **sorted, int arr_size)
{
	int i;
	int j;
	int num;
	int bit;
	int concat;

	i = 0;
	concat = 0;	
	while (i < arr_size)
	{
		num = (*sorted)[i];
		j = 31;
		bit = 0;
		while (j >= 0)
		{
			bit = num >> j;
			if (bit & 1)
				bit = 1;
			else
				bit = 0;
			concat = concat * 10;
			concat = concat + bit;				
			j--;	
		}
		(*sorted)[i] = concat;
		i++;
	}
}

int main	(int argc, char **argv)
{
	t_stacks stack;
	int i;
	int j;
	
	i = 0;
	j = 0;
	
	stack.A.arr_sizeA = argc - 1;
	stack.B.arr_sizeB = 0;
	stack.args_size = argc - 1;
	stack.A.arrA = (int *)malloc(sizeof(int) * stack.A.arr_sizeA);
	stack.group_arr = (int *)malloc(sizeof(int) * stack.A.arr_sizeA);
	//stack.group_arr = (int *)malloc(sizeof(int) * stack.A.arr_sizeA);
	stack.B.arrB =  NULL; //ft_calloc(argc - 1, sizeof(int));

	while(i < stack.A.arr_sizeA)
	{
		if (!ft_isdigit_negative(argv[i + 1][0]))
			error();
		j++;
		stack.group_arr[i] = ft_atoi(argv[j]);
		stack.A.arrA[i] = ft_atoi(argv[j]);	
		i++;
		
				
	}
	//stack.group_arr = stack.A.arrA;
	i = is_sorted(stack.A.arrA, stack.A.arr_sizeA, stack.B.arr_sizeB);
	j = is_duplicated(stack.A.arrA, stack.A.arr_sizeA);
	if (i == 1 || j == 1)
		error();
	
	//memcpy(&stack.group_arr, &stack.A.arrA, stack.A.arr_sizeA - 1);

	

	print_test(&stack);
	

	/* print_test(&stack);
	brute_force(&stack);
	print_test(&stack); */

	group_numbers(stack.group_arr, stack.A.arr_sizeA);	
	print_test(&stack);

	index_group(stack.A.arrA, &stack.group_arr, stack.A.arr_sizeA);

	print_test(&stack);

	binary_convert(&stack.group_arr, stack.A.arr_sizeA);

	print_test(&stack);

	
	/* pb(&stack);
	pa(&stack);	
	
	ra(&stack.A);
	ra(&stack.A);

	sa(&stack, 0);

	pb(&stack);
	pb(&stack);
	pb(&stack);	
	
	rb(&stack.B);
	rr(&stack.A, &stack.B);
	rra(&stack.A);
	rrb(&stack.B);
	rrr(&stack.A, &stack.B);

	pa(&stack);
	ss(&stack);
	sb(&stack, 0);
	pa(&stack);

	sb(&stack, 0);
	ss(&stack);
	print_test(&stack); */
		

	free(stack.A.arrA);
	free(stack.B.arrB);	
	free(stack.group_arr);
	return (0);
}