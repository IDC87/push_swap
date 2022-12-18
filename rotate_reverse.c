/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:10:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/18 18:12:36 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(stackA *A)
{
	rotate_down(&(A->arrA), &(A->arr_sizeA));
}

void rrb(stackB *B)
{
	rotate_down(&(B->arrB), &(B->arr_sizeB));
}

void rrr(stackA *A, stackB *B)
{
	rotate_down(&(A->arrA), &(A->arr_sizeA));
	rotate_down(&(B->arrB), &(B->arr_sizeB));
}