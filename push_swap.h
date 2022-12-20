/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:56:37 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/20 18:24:09 by ivda-cru         ###   ########.fr       */
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

int is_sorted(const int *arr, int arr_size, int arr_sizeB);
int is_duplicated(const int *arr, int arr_size);
void error(void);

void	sa(t_stacks *swap, int lever);
void	sb(t_stacks *swap, int lever);
void	ss(t_stacks *swap);
void pa(t_stacks *stack);
void pb(t_stacks *stack);
void rotate_up(int **arr, int *arr_size);
void rotate_down(int **arr, int *arr_size);
void ra(stackA *A);
void rb(stackB *B);
void rr(stackA *A, stackB *B);
void rra(stackA *A);
void rrb(stackB *B);
void rrr(stackA *A, stackB *B);


#endif