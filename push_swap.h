/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:56:37 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/07 02:24:35 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"

#define n_bits 9

// 9 bits for 500 stack numbers
// 7 bits for 100


typedef struct s_stacks
{

	int *arrA;
	int arr_sizeA;	

	int *arrB;
	int arr_sizeB;	
	
	char **stringA;
	char **stringB;	
	
	int *sorted_arr;
	int n_iterarions;

	size_t bits;
	
}	t_stacks;

void print_test(t_stacks *ps);
void print_array(t_stacks *p);

int is_sorted(const int *arr, int arr_size);
int is_duplicated(const int *arr, int arr_size);
int	ft_isdigit_negative(int c);
void error(void);


void ra_string(t_stacks *list);
void rotate_up_string(char **arr, int arr_size);
char *pop_element(t_stacks *bits, char** arr, int* size);
void pb_string(t_stacks *str);
char **pushArrayFront(t_stacks *bits, char** arr, int* size, char* element);
void pa_string(t_stacks *str);
void free_mem(char **list, int rows);

void short_solve(t_stacks *S); // tvz nao precise de estar aqui se a mudar para a medium solve file
void medium_solve(t_stacks *list);

void	sa(t_stacks *swap);
void ra(t_stacks *list);
void rra(t_stacks *list);
int pop_item(int **arr, int *arr_size);
void pa(t_stacks *stack);
void pb(t_stacks *stack);

#endif