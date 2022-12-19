/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/19 23:14:19 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

//https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e


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
	stack.B.arrB = ft_calloc(argc - 1, sizeof(int));

	while(i < stack.A.arr_sizeA)
	{
		if (!ft_isdigit(argv[i + 1][0]))
			error();
		if (argv[i + 1][0] > __INT_MAX__) // isto nao esta bem, corrigir mais tarde
			error();
		stack.A.arrA[i++] = ft_atoi(argv[++j]);			
	}
	
	i = is_sorted(stack.A.arrA, stack.A.arr_sizeA);
	j = is_duplicated(stack.A.arrA, stack.A.arr_sizeA);
	if (i == 1 || j == 1)
		error();
	
	
	ft_printf("ORIGINAL STACK\n\n");
	print_test(&stack);

		
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