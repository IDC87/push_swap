/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:42:37 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/09 15:34:12 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra_string(t_stacks *list)
{	
	if (list->arr_sizeA > 1)
	{
		rotate_up_string((list->stringA), (list->arr_sizeA));
		ft_putendl_fd("ra", 1);
		//ft_printf("ra\n");
		list->n_iterarions++;	
	}
}

void pb_string(t_stacks *str)
{
	char *popped;	
	popped = pop_element(str, str->stringA, &str->arr_sizeA);
	str->stringB = pushArrayFront(str, str->stringB, &str->arr_sizeB, popped);
	ft_putendl_fd("pb", 1);
	//ft_printf("pb\n");
	str->n_iterarions++;
	free(popped);
}

void pa_string(t_stacks *str)
{
	char *popped;	
	popped = pop_element(str, str->stringB, &str->arr_sizeB);
	str->stringA = pushArrayFront(str, str->stringA, &str->arr_sizeA, popped);
	ft_putendl_fd("pa", 1);
	//ft_printf("pa\n");
	str->n_iterarions++;
	free(popped);	
}

char **pushArrayFront(t_stacks *bits, char **arr_push, int *size, char* element)
{
    int i;
	char** newArr;
	
	i = 1;
    (*size)++;    
    newArr = (char **)malloc(sizeof(char *) * (*size));
    newArr[0] = (char *)malloc((sizeof(char) * (ft_strlen(element) + 1)));
    ft_memcpy(newArr[0], element, bits->bits + 1);    
	if (*size > 1)
	{
		while (i < *size)
		{
			newArr[i] = (char *)malloc((ft_strlen(arr_push[i - 1]) + 1) * sizeof(char));
			ft_memcpy(newArr[i], arr_push[i - 1], bits->bits + 1);
			i++;
		}		
	}
	free_mem(arr_push, *size - 1);
    arr_push = newArr;   
	return arr_push;
}

char *pop_element(t_stacks *bits, char** arr_pop, int* size)
{
	int i;
	char *tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) *(bits->bits + 1));
		if (!tmp)
			return (NULL);
	ft_memcpy(tmp, arr_pop[0], bits->bits + 1);
    free(arr_pop[0]);

	while (i < *size - 1)
    {
        arr_pop[i] = arr_pop[i + 1];
		i++;
    }
    (*size)--;
	return tmp;
}