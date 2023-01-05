/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/05 01:38:05 by ivda-cru         ###   ########.fr       */
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
        list->stringA[i] = (char *)malloc(sizeof(char) * n_bits + 1);
        num = arr[i];
		j = n_bits - 1;
		while (j >= 0)
        {
            list->stringA[i][j] = (num % 2) + '0';
            num /= 2;
			j--;
        }
        list->stringA[i][n_bits] = '\0';
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
	while(i < n_bits)
	{
		j = 0;
		while (j < max_len)
		{
			if ((list->stringA[0][n_bits - 1 - i]) == '1')
				ra_void(list);
			else
				pb_string(list);
			j++;
		}
		i++;
		while (list->arr_sizeB != 0)
			pa_string(list);
	}	
}

int* binary_to_decimal(char** binary, int n) 
{
    int* decimal = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int len = ft_strlen(binary[i]);
        decimal[i] = 0;
        for (int j = 0; j < len; j++) {
            decimal[i] = decimal[i] * 2 + (binary[i][j] - '0');
        }
    }
    return decimal;
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


int main	(int argc, char **argv)
{
	t_stacks stack;
	int i;
	int j;
	
	i = 0;
	j = 0;
	
	stack.arr_sizeA = argc - 1;
	stack.arr_sizeB = 0;
	stack.arrA = (int *)malloc(sizeof(int) * stack.arr_sizeA);
	stack.sorted_arr = (int *)malloc(sizeof(int) * stack.arr_sizeA);
	stack.stringA = NULL;
	stack.stringB = NULL;
	stack.n_iterarions = 0;

	while(i < stack.arr_sizeA)
	{
		if (!ft_isdigit_negative(argv[i + 1][0]))
			error();
		j++;
		stack.sorted_arr[i] = ft_atoi(argv[j]);
		stack.arrA[i] = ft_atoi(argv[j]);	
		i++;				
	}
	i = is_sorted(stack.arrA, stack.arr_sizeA, stack.arr_sizeB);
	j = is_duplicated(stack.arrA, stack.arr_sizeA);
	if (i == 1 || j == 1)
		error();

	bubble_sort(stack.sorted_arr, stack.arr_sizeA);
	index_group(stack.arrA, &stack.sorted_arr, stack.arr_sizeA);
	binary_string(&stack, stack.sorted_arr, stack.arr_sizeA);	

	logic_operations(&stack);
	
	//print_test(&stack);

	

	

	free(stack.arrA);	
	free(stack.sorted_arr);
	free_mem(stack.stringA, stack.arr_sizeA);
	free_mem(stack.stringB, stack.arr_sizeB);
	return (0);
}