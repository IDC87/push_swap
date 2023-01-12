/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:42:37 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/12 08:18:34 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_string(t_stacks *list)
{	
	if (list->arr_size_a > 1)
	{
		rotate_up_string((list->string_a), (list->arr_size_a));
		ft_putendl_fd("ra", 1);
		list->n_iterarions++;
	}
}

void	pb_string(t_stacks *str)
{
	char	*popped;

	popped = pop_element(str, str->string_a, &str->arr_size_a);
	str->string_b = push_element(str, str->string_b, &str->arr_size_b, popped);
	ft_putendl_fd("pb", 1);
	str->n_iterarions++;
	free(popped);
}

void	pa_string(t_stacks *str)
{
	char	*popped;

	popped = pop_element(str, str->string_b, &str->arr_size_b);
	str->string_a = push_element(str, str->string_a, &str->arr_size_a, popped);
	ft_putendl_fd("pa", 1);
	str->n_iterarions++;
	free(popped);
}

char	**push_element_2(t_stacks *bits, char **newArr, char **push, int *size)
{
	int	i;

	i = 1;
	while (i < *size)
	{
		newArr[i] = (char *)malloc((ft_strlen(push[i - 1]) + 1) \
		* sizeof(char));
		ft_memcpy(newArr[i], push[i - 1], bits->bits + 1);
		i++;
	}
	return (newArr);
}

char	**push_element(t_stacks *bits, char **push, int *size, char *element)
{
	char	**new_arr;

	(*size)++;
	new_arr = (char **)malloc(sizeof(char *) * (*size));
	new_arr[0] = (char *)malloc((sizeof(char) * (ft_strlen(element) + 1)));
	ft_memcpy(new_arr[0], element, bits->bits + 1);
	if (*size > 1)
		new_arr = push_element_2(bits, new_arr, push, size);
	free_mem(push, *size - 1);
	push = new_arr;
	return (push);
}
