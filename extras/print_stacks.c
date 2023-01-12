/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:28:33 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/12 08:55:12 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// void print_test(t_stacks *ps)
// {
// 	int i = -1;
// 	static int display_counter;

// 	ft_printf("\n-------------------------\n");	
// 	ft_printf("SIZE A: [%d]", ps->arr_size_a);
// 	ft_printf("  || SIZE B: [%d]", ps->arr_size_b);
// 	ft_printf("  ||  PRINT N[%d]", ++display_counter);
// 	ft_printf("  ||  NUMBER OF OPERATIONS: [%d]\n", ps->n_iterarions);	
// 	ft_printf("\nSTACK A\n");
// 	while (i++ < ps->arr_size_a - 1)
// 		ft_printf("[%d]", ps->arr_a[i]);
// 	ft_printf("\n");	

// 	ft_printf("\nSTACK B\n");
// 	if (ps->arr_b != NULL && ps->arr_size_b != 0)
// 	{
// 		i = -1;		
// 		while (i++ < ps->arr_size_b - 1)
// 			ft_printf("[%d]", ps->arr_b[i]);
// 		ft_printf("\n");		
// 	}
// 	else
// 		ft_printf("[///EMPTY\\\\]");		
// 	i = -1;
// 	ft_printf("\n\nGROUP STACK\n");
// 	while (i++ < ps->arr_size_a - 1)
// 			ft_printf("[%d]", ps->sorted_arr[i]);

// 	ft_printf("\n\nSTRING BIT ARRAY A\n");
// 	if (ps->string_a != NULL)
// 	{
// 		i = -1;		
// 		while (i++ < ps->arr_size_a - 1)
// 				ft_printf("[%s]", ps->string_a[i]);
// 		ft_printf("\n");		
// 	}
// 	else
// 		ft_printf("[///EMPTY\\\\]");		
// 	ft_printf("\nSTRING BIT ARRAY B\n");
// 	if (ps->string_b != NULL && ps->arr_size_b != 0)
// 	{
// 		i = 0;		
// 		while (i < ps->arr_size_b)
// 		{
// 				ft_printf("[%s]", ps->string_b[i]);
// 				i++;
// 		}
// 	}
// 	else
// 		ft_printf("[///EMPTY\\\\]");
// 	ft_printf("\n-------------------------\n");
// 	ft_printf("\n");		
// 	ft_printf("\n");
// }