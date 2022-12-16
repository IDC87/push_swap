/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:28:33 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/16 17:00:01 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  void print_array(t_stacks *p)
{
	int i;

	i = 0;
	
	
	if (p->A.arr_sizeA > p->B.arr_sizeB)
	{
		while (i < p->A.arr_sizeA)
		{			
			while ((p->A.arr_sizeA - p->B.arr_sizeB - i) > 0)
			{
				ft_printf("%d\t\t\n", p->A.arrA[i]);
				i++;
			}
			if (i != p->A.arr_sizeA)
			{
				if (p->A.arrA[i] >= 100)
					ft_printf("%d\t\t%d\n", p->A.arrA[i], p->B.arrB[p->A.arr_sizeA - i - 1]);
				else if (p->A.arrA[i] < 100 && p->A.arrA[i] >= 10)
					ft_printf("%d\t\t%d\n", p->A.arrA[i], p->B.arrB[p->A.arr_sizeA - i - 1]);
				else
					ft_printf("%d\t\t%d\n", p->A.arrA[i], p->B.arrB[p->A.arr_sizeA - i - 1]);
				i++;				
			}
		}
		ft_printf("----\t\t----\n");
		ft_printf("a\t\tb\n");
		
	}
	i = 0;
	if (p->B.arr_sizeB > p->A.arr_sizeA)
	{
		while (i < p->B.arr_sizeB)
		{
			while ((p->B.arr_sizeB - p->A.arr_sizeA - i) > 0)
			{
				ft_printf("\t\t%d\n", p->B.arrB[p->B.arr_sizeB - 1 - i]);
				i++;
			}
			if (i != p->A.arr_sizeA)
			{
				//if (p->B.arrB[i] >= 100)
					ft_printf("%d\t\t%d\n", p->A.arrA[p->A.arr_sizeA - p->B.arr_sizeB + i], p->B.arrB[p->B.arr_sizeB - i - 1]);
				// else if (p->stackB[i] < 100 && p->stackB[i] >= 10)
				//	ft_printf("%d       %d\n", p->A.arrA[i], p->stackB[p->arr_sizeB - i - 1]);
				//else
				//	ft_printf("%d        %d\n", p->A.arrA[i], p->stackB[p->arr_sizeB - i - 1]); 
				i++;				
			}
		}
		ft_printf("----\t\t----\n");
		ft_printf("a\t\tb\n");
		
	}

	ft_printf("-------------------\n");
	ft_printf("-------------------\n");
	ft_printf("\n\n"); 
	
} */

void print_test(t_stacks *ps)
{
	int i = -1;

	
	ft_printf("\nSTACK A\n");
	while (i++ < ps->A.arr_sizeA - 1)
		ft_printf("[%d]", ps->A.arrA[i]);
	ft_printf("\n\n");
	i = -1;	
	ft_printf("STACK B\n");
	while (i++ < ps->B.arr_sizeB - 1)
		ft_printf("[%d]", ps->B.arrB[i]);

	ft_printf("\n\nSIZE of original array: %d\n", ps->args_size);
	ft_printf("SIZE of array A: %d\n", ps->A.arr_sizeA);
	ft_printf("SIZE of array B: %d\n", ps->B.arr_sizeB);
	ft_printf("\n\n");
		
	
}