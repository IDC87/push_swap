/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:15:16 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/05 01:33:22 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

void rotate_up_string(char** arr, int size)
{
	int i;
    char* temp;
	
	i = 0;
	temp = arr[0];
	while (i < size - 1)
    {
        arr[i] = arr[i + 1];
		i++;
    }
    arr[size - 1] = temp;
}

void ra_void(t_stacks *list)
{	
	if (list->arr_sizeA > 1)
	{
		rotate_up_string((list->stringA), (list->arr_sizeA));
		ft_printf("ra\n");
		list->n_iterarions++;	
	}
}

char *pop_element(char** arr_pop, int* size)
{
	int i;
	char *tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) *(n_bits + 1));
	ft_memcpy(tmp, arr_pop[0], n_bits + 1);
    free(arr_pop[0]);

	while (i < *size - 1)
    {
        arr_pop[i] = arr_pop[i + 1];
		i++;
    }
    (*size)--;
	return tmp;
}

char **pushArrayFront(char **arr_push, int *size, char* element)
{
    int i;
	char** newArr;
	
	i = 1;
    (*size)++;    
    newArr = (char **)malloc(sizeof(char *) * (*size));
    newArr[0] = (char *)malloc((sizeof(char) * (ft_strlen(element) + 1)));
    ft_memcpy(newArr[0], element, n_bits + 1);    
	if (*size > 1)
	{
		while (i < *size)
		{
			newArr[i] = (char *)malloc((ft_strlen(arr_push[i - 1]) + 1) * sizeof(char));
			ft_memcpy(newArr[i], arr_push[i - 1], n_bits + 1);
			i++;
		}		
	}
	free_mem(arr_push, *size - 1);
    arr_push = newArr;   
	return arr_push;
}

void pb_string(t_stacks *str)
{
	char *popped;	
	popped = pop_element((str->stringA), &str->arr_sizeA);
	str->stringB = pushArrayFront((str->stringB), &str->arr_sizeB, popped);
	ft_printf("pb\n");
	str->n_iterarions++;
	free(popped);
}

void pa_string(t_stacks *str)
{
	char *popped;	
	popped = pop_element((str->stringB), &str->arr_sizeB);
	str->stringA = pushArrayFront((str->stringA), &str->arr_sizeA, popped);
	ft_printf("pa\n");
	str->n_iterarions++;
	free(popped);	
}
