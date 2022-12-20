/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/20 23:37:36 by ivda-cru         ###   ########.fr       */
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
	stack.B.arrB =  NULL; //ft_calloc(argc - 1, sizeof(int));

	while(i < stack.A.arr_sizeA)
	{
		if (!ft_isdigit(argv[i + 1][0]))
			error();
		if (argv[i + 1][0] > __INT_MAX__) // isto nao esta bem, corrigir mais tarde
			error();
		stack.A.arrA[i++] = ft_atoi(argv[++j]);			
	}
	
	i = is_sorted(stack.A.arrA, stack.A.arr_sizeA, stack.B.arr_sizeB);
	j = is_duplicated(stack.A.arrA, stack.A.arr_sizeA);
	if (i == 1 || j == 1)
		error();
	
	
	

	print_test(&stack);

	//if (stack.A.arr_sizeA == 3)
		//brute_force(&stack);

	

	
	//sa(&stack, 0);
	//print_test(&stack);
	
	//rra(&stack.A);
	print_test(&stack);
	
		
	pb(&stack);
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
	print_test(&stack);
		

	free(stack.A.arrA);
	free(stack.B.arrB);	
	return (0);
}