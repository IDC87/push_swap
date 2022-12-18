/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:56:37 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/18 17:25:20 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"

typedef struct stackA
{
	int *arrA;
	int arr_sizeA;	
}	stackA;

typedef struct stackB
{
	int *arrB;
	int arr_sizeB;	
}	stackB;


typedef struct s_stacks
{
	stackA A;
	stackB B;
	int poped_item;
	int stacked_item;
	int args_size;	
}	t_stacks;

void print_test(t_stacks *ps);
void print_array(t_stacks *p);

void	sa(t_stacks *swap);
void	sb(t_stacks *swap);
void	ss(t_stacks *swap);

void pa(t_stacks *stack);
void pb(t_stacks *stack);

void ra(stackA *A);
void rb(stackB *B);
void rr(stackA *A, stackB *B);


#endif