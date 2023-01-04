/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:56:37 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/04 20:45:58 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"

#define n_bits 9

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
	char **stringA;
	char **stringB;
	char *tmp;
	int *group_arr;
	int n_iterarions;
	int poped_item;
	int stacked_item;
	int args_size;	
}	t_stacks;

void print_test(t_stacks *ps);
void print_array(t_stacks *p);

int is_sorted(const int *arr, int arr_size, int arr_sizeB);
int is_duplicated(const int *arr, int arr_size);
int	ft_isdigit_negative(int c);
void error(void);

void	sa(t_stacks *swap, int lever);
void	sb(t_stacks *swap, int lever);
void	ss(t_stacks *swap);
void pa(t_stacks *stack);
void pb(t_stacks *stack);
void rotate_up(int **arr, int *arr_size);
void rotate_down(int **arr, int *arr_size);
void ra(t_stacks *list);
void rb(stackB *B);
void rr(stackA *A, stackB *B);
void rra(stackA *A);
void rrb(stackB *B);
void rrr(stackA *A, stackB *B);

void ra_void(t_stacks *list);
void rotate_up_string(char **arr, int arr_size);
char *pop_element(char** arr, int* size);
void pb_string(t_stacks *str);
char **pushArrayFront(char** arr, int* size, char* element);
void pa_string(t_stacks *str);

#endif