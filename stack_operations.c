/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:58:08 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/20 16:43:59 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *swap, int lever)
{
	int tmp;

	tmp = 0;	
	if (swap->A.arr_sizeA > 1)	
	{
		tmp = swap->A.arrA[0];
		swap->A.arrA[0] = swap->A.arrA[1];
		swap->A.arrA[1] = tmp;
		if (lever != 1)
			ft_printf("sa\n");	
	}
}

void	sb(t_stacks *swap, int lever)
{
	int tmp;

	tmp = 0;
	if (swap->B.arr_sizeB > 1)	
	{
		tmp = swap->B.arrB[swap->B.arr_sizeB - 1];
		swap->B.arrB[swap->B.arr_sizeB - 1] = swap->B.arrB[swap->B.arr_sizeB - 2];
		swap->B.arrB[swap->B.arr_sizeB - 2] = tmp;
		if (lever != 1)
			ft_printf("sb\n");		
	}
}

void	ss(t_stacks *swap)
{
		
	sa(swap, 1);
	sb(swap, 1);
	ft_printf("ss\n");
}