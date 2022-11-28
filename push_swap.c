/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/11/25 18:11:03 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

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

int main	(int argc, char **argv)
{
	int *stackA;
	int *stackB;
	int arr_size;
	int i;
	int j;

	i = 0;	
	j = 1;
	arr_size = argc - 1;
	ft_printf("%d arguments", arr_size);
	ft_printf("\n\n");
	stackA = (int *)malloc(sizeof(int) * arr_size);
	stackB = (int *)malloc(sizeof(int) * arr_size);
	//stackA = NULL;
	stackB = NULL;
	
	while(arr_size > 0)
	{
		stackA[i] = ft_atoi(argv[j]);
		i++;
		j++;
		arr_size--;
		
	}
	ft_printf("Original Stack\n");
	j = 0;
	arr_size = argc - 1;
	while(j < arr_size)
		ft_printf("[%d]", stackA[j++]);
	ft_printf("\n\n");
	
	ft_printf("Sa - Swap the first 2 elements operation!\n");
	sa_sb_ss_swap(stackA);
	i = argc - 1;
	while(i-- > 0)
		ft_printf("[%d]", *stackA++);
	ft_printf("\n\n");
	
	//free(stackB);
	//free(stackA);
	return (0);
}