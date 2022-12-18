/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/18 17:28:49 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e


void error(void)
{
	ft_printf("Error\n");
	exit(0);
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

	
	print_test(&stack);

	free(stack.A.arrA);
	free(stack.B.arrB);	
	return (0);
}