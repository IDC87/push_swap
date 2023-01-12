/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:56:37 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/11 06:44:06 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stacks
{
	int		*arr_a;
	int		arr_size_a;
	int		*arr_b;
	int		arr_size_b;
	char	**string_a;
	char	**string_b;
	int		*sorted_arr;
	int		n_iterarions;
	int		bits;	
}	t_stacks;

void	print_test(t_stacks *ps);

int		is_sorted(const int *arr, int arr_size);
int		is_sorted_args(int arg_count, char **args);
int		is_duplicated(int arg_count, char **args);
int		ft_isdigit_negative(int c);
void	error(char **str, int arg_count);
int		check_int_limits(long int num);
void	medium_solve(t_stacks *list, int arg_count);
void	bubble_sort(int *new_arr, int arr_size);
void	index_group(const int *A, int **sorted, int arr_size);
void	go_radix(t_stacks *stack, int n_args);
void	ra_string(t_stacks *list);
void	rotate_up(int **arr, int *arr_size);
void	rotate_down(int **arr, int *arr_size);
void	rotate_up_string(char **arr, int arr_size);
char	*pop_element(t_stacks *bits, char **arr, int *size);
void	push_item(int **arr, int *arr_size, int value);
void	pb_string(t_stacks *str);
char	**push_element(t_stacks *bits, char **arr, int *size, char *element);
void	pa_string(t_stacks *str);
void	free_mem(char **list, int rows);
void	sa(t_stacks *swap);
void	ra(t_stacks *list);
void	rra(t_stacks *list);
int		pop_item(int **arr, int *arr_size);
void	pa(t_stacks *stack);
void	pb(t_stacks *stack);
#endif