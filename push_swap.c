/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/18 20:43:07 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

//https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e


void error(void)
{
	ft_printf("Error\n");
	exit(0);
}

int is_sorted(stackA *stackA, int *arr, int arr_size)
{
	int i;
	int j;
	int tmp;
	
	i = 0;
	j = 0;
		while (i < arr_size - 1)
		{
			j = 0;
			while(j < arr_size - 1 - i)
			{
				if (arr[j] > arr[j + 1])
				{
					tmp = arr[j];
        			arr[j] = arr[j + 1];
        			arr[j + 1] = tmp;			
				}				
				j++;				
			}
			i++;			
		}
		if (!ft_memcmp(arr, stackA->arrA, arr_size))
			return (1);
}

int main	(int argc, char **argv)
{
	t_stacks stack;
	int i;
	int j;
	
	i = 0;
	j = 1;
	
	stack.A.arr_sizeA = argc - 1;
	stack.B.arr_sizeB = 0;
	stack.args_size = argc - 1;
	stack.A.arrA = (int *)malloc(sizeof(int) * stack.A.arr_sizeA);
	stack.B.arrB = ft_calloc(argc - 1, sizeof(int));

	while(i < stack.A.arr_sizeA)
	{
		stack.A.arrA[i] = ft_atoi(argv[j]);
		i++;
		j++;		
	}
	
	ft_printf("ORIGINAL STACK\n\n");
	print_test(&stack);

	//int *sorted_array = is_sorted(stack.A.arrA, stack.A.arr_sizeA);
	
	int *new_arr;

	new_arr = (int *)malloc(sizeof(int) * stack.A.arr_sizeA);
	ft_memcpy(new_arr, stack.A.arrA, stack.A.arr_sizeA);
	new_arr = stack.A.arrA;

	is_sorted(&stack.A, new_arr, stack.A.arr_sizeA);

	i = -1;
	while (i++ < stack.A.arr_sizeA - 1)
		ft_printf("sorted array [%d]\n", new_arr[i]);


	
	/* pb(&stack);
	pa(&stack);	
	
	ra(&stack.A);
	ra(&stack.A);

	sa(&stack);

	pb(&stack);
	pb(&stack);
	pb(&stack);	
	
	rb(&stack.B);
	rr(&stack.A, &stack.B);
	rra(&stack.A);
	rrb(&stack.B);
	rrr(&stack.A, &stack.B); */
		
	print_test(&stack);

	free(stack.A.arrA);
	free(stack.B.arrB);	
	return (0);
}