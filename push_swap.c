/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/11/28 21:58:08 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

int *intdup(int const *src, size_t len)
{
   int *p = (int *)malloc(len * sizeof(int));
   ft_memcpy(p, src, len * sizeof(int));
   return p;
}


void pa_pb_push(t_stacks *push)
{
	int *tmp;
	int i;
	static int j;
	
	i = -1;
	tmp = intdup(push->stackA, push->arr_size);
	free(push->stackA);
	push->stackA = (int *)malloc(sizeof(int) * (push->arr_size - 1));	
	while (i++ < push->arr_size - 1)
		push->stackA[i] = tmp[i + 1];
	push->stackB[j] = tmp[0];	
	j++;
	push->arr_size--;
	free(tmp);

}


int *sa_sb_ss_swap(int *stack)
{
	int tmp;

	tmp = 0;	
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;	

	return (stack);
}

void error(void)
{
	ft_printf("Error\n");
	exit(0);
}

void print_array(t_stacks *p)
{
	int i;

	i = 0;
	ft_printf("\n---------------\n");
	ft_printf("---------------\n");
	ft_printf("%d array size", p->arr_size);
	ft_printf("\n\n");
	
	while (i < p->arr_size)
	{
		ft_printf("%d", p->stackA[i]);
		if (p->stackB[(p->arr_size - 1) - i] == 0)
			ft_printf("\n");
		else
			ft_printf("   %d\n", p->stackB[(p->arr_size - 1) - i]);
		i++;
		if (i == p->arr_size)
			ft_printf("----- -----\na     b\n");
		// falta organizar a ordem dos inteiros
	}	
}

int main	(int argc, char **argv)
{
	t_stacks stack;
	int i;
	int j;
	
	i = 0;
	j = 1;
	stack.arr_size = argc - 1;
	stack.stackA = (int *)malloc(sizeof(int) * stack.arr_size);
	stack.stackB = (int *)malloc(sizeof(int) * stack.arr_size);

	while(i < stack.arr_size)
	{
		stack.stackA[i] = ft_atoi(argv[j]);
		stack.stackB[i] = 0;
		i++;
		j++;		
	}
	print_array(&stack);


	sa_sb_ss_swap(stack.stackA);
	print_array(&stack);
	

	pa_pb_push(&stack);
	print_array(&stack);

	pa_pb_push(&stack);
	print_array(&stack);

	pa_pb_push(&stack);
	print_array(&stack);

	free(stack.stackA);
	free(stack.stackB);
	
	return (0);
}