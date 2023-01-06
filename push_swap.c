/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/06 01:25:03 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>



void bubble_sort(int *new_arr, int arr_size) // novo nome sort_array
{
	int i;
	int j;
	int tmp;

	i = 0;	
	while (i < arr_size - 1)
		{
			j = 0;
			while(j < arr_size - 1 - i)
			{
				if ((new_arr)[j] > (new_arr)[j + 1])
				{
					tmp = (new_arr)[j];
               	 	(new_arr)[j] = (new_arr)[j + 1];
                	(new_arr)[j + 1] = tmp;					
				}
				j++;				
			}
			i++;			
		}	
}

void index_group(const int *A, int **sorted, int arr_size)
{
	int i;
	int j;
	int *index_arr;
	
	index_arr = (int *)malloc(sizeof(int) * arr_size);
	i = 0;
	while (i < arr_size)
	{
		j = 0;
		while (j < arr_size )
		{
			if (A[i] ==  (*sorted)[j])
			{
				index_arr[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	i = -1;
	while (i++ < arr_size - 1)
		(*sorted)[i] = index_arr[i];
	free(*sorted);
	(*sorted) = index_arr;	
}


void binary_string(t_stacks *list, int *arr, int size) 
{
	int i;
	int j;
	int num;

	i = 0;
    list->stringA = (char **)malloc(sizeof(char *) * size);
    while (i < size)
	{
        list->stringA[i] = (char *)malloc(sizeof(char) * list->bits + 1);
        num = arr[i];
		j = list->bits - 1;
		while (j >= 0)
        {
            list->stringA[i][j] = (num % 2) + '0';
            num /= 2;
			j--;
        }
        list->stringA[i][list->bits] = '\0';
		i++;
    }
}


void logic_operations(t_stacks *list)
{
	int i;
	int j;
	int max_len;
	//int usefull_bits;

	i = 0;
	j = 0;
	max_len = list->arr_sizeA;	
	while(i < list->bits)
	{
		j = 0;
		while (j < max_len)
		{
			if ((list->stringA[0][list->bits - 1 - i]) == '1')
				ra_string(list);
			else
				pb_string(list);
			j++;
		}
		i++;
		while (list->arr_sizeB != 0)
			pa_string(list);
	}	
}


void free_mem(char **list, int rows)
{
	int i;
	i = 0;
	while (i < rows)  
    {
        free(list[i]);
		i++;
    }
    free(list);   
}

/* void short_solve(t_stacks *list)
{
	if (list->arr_sizeA == 2)
		ft_printf("sa\n");
	else if (list->arr_sizeA == 3)	
	{
		if (list->sorted_arr[0] == 2)
		{
			ft_printf("ra\n");
			if (list->sorted_arr[1] == 1)
				ft_printf("sa\n");			
		}
		else if (list->sorted_arr[0] == 1)
		{
			if (list->sorted_arr[1] == 0)
				ft_printf("sa\n");
			else
				ft_printf("rra\n");
		}
		else if (list->sorted_arr[0] == 0)
		{
			if (list->sorted_arr[1] == 2)
				ft_printf("sa\nra\n");
		}
	}
} */

void short_solve(t_stacks *S)
{
	if (S->sorted_arr[0] > S->sorted_arr[1])
	{
		if (S->sorted_arr[1] > S->sorted_arr[2])
		{
			ra(S);
			sa(S);
		}
		else if (S->sorted_arr[0] > S->sorted_arr[2])
			ra(S);
		else
			sa(S);	
	}
	else if (S->sorted_arr[1] > S->sorted_arr[2])
	{
		if (S->sorted_arr[0] > S->sorted_arr[2])
			rra(S);
		else
		{
			sa(S);
			ra(S);				
		}		
	}	
}

void go_radix(t_stacks *stack, int n_args)
{
	if (n_args > 4 && n_args <= 12)
		stack->bits = 3;
	else if (n_args > 12 && n_args <= 100)
		stack->bits = 7;
	else if (n_args > 100 && n_args <= 500)
		stack->bits = 9;
		
	binary_string(stack, stack->sorted_arr, stack->arr_sizeA);
	logic_operations(stack);
	free_mem(stack->stringA, stack->arr_sizeA);
	free_mem(stack->stringB, stack->arr_sizeB);
}



int	check_minimax(char *str)
{
	long long	nb;

	nb = ft_atoi(str);
	if (nb > 2147483647 || nb < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}


int main	(int argc, char **argv)
{
	t_stacks stack;
	int i;
	int j;
	
	i = 0;
	j = 0;

	if (argc == 1)
		exit(0);
	
	stack.arr_sizeA = argc - 1;
	stack.arr_sizeB = 0;
	stack.arrA = (int *)malloc(sizeof(int) * stack.arr_sizeA);
	stack.arrB = NULL;
	stack.sorted_arr = (int *)malloc(sizeof(int) * stack.arr_sizeA);
	stack.stringA = NULL;
	stack.stringB = NULL;
	stack.n_iterarions = 0;
	stack.bits = 9;

	
		
	while(i < stack.arr_sizeA)
	{
		if (!ft_isdigit_negative(argv[i + 1][0]))
			error();
		j++;
		stack.sorted_arr[i] = ft_atoi(argv[j]);
		stack.arrA[i] = ft_atoi(argv[j]);	
		i++;				
	}
	if(is_sorted(stack.arrA, stack.arr_sizeA, stack.arr_sizeB))
		exit(0);
	if (is_duplicated(stack.arrA, stack.arr_sizeA))
		error();

	bubble_sort(stack.sorted_arr, stack.arr_sizeA);
	index_group(stack.arrA, &stack.sorted_arr, stack.arr_sizeA);
	
	if (argc - 1 >= 2 && argc - 1 <= 3)
		short_solve(&stack);
	else if (argc - 1 == 5)
		medium_solve(&stack);
	else if (argc - 1 > 5)
		go_radix(&stack, argc - 1);
	
	
	
		
		
		/* stack.bits = 7;
	else if (argc - 1 <= 255)
		stack.bits = 8;
	else if (argc - 1 <= 500)
		stack.bits = 9;
 */
	//print_test(&stack);
	
	
	
	//print_test(&stack);

	

	

	free(stack.arrA);	
	free(stack.sorted_arr);
	
	return (0);
}