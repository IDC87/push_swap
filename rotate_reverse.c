/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:10:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/20 23:43:47 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(stackA *A)
{
	if (A->arr_sizeA > 1)
	{
		rotate_down(&(A->arrA), &(A->arr_sizeA));
		ft_printf("rra\n");		
	}
}

void rrb(stackB *B)
{
	if (B->arr_sizeB > 1)
	{
		rotate_down(&(B->arrB), &(B->arr_sizeB));
		ft_printf("rrb\n");		
	}
}

void rrr(stackA *A, stackB *B)
{
	if (A->arr_sizeA > 1)
		rotate_down(&(A->arrA), &(A->arr_sizeA));
	if (B->arr_sizeB > 1)
		rotate_down(&(B->arrB), &(B->arr_sizeB));
	ft_printf("rrr\n");
}