/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:27:32 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/08 04:20:33 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_smallest(const int *array, int size, int value)
{
    int i;	
	
	i = 0;
	while (i < size)
	{
        if (array[i] == value)        
            break;
		i++;
	}    
    return i;
}

void rotate_and_push(t_stacks *list, int index)
{
	int min_counter;
	int i;

	i = 0;
	min_counter = find_smallest(list->sorted_arr, list->arr_sizeA, index);
		if (min_counter <= list->arr_sizeA / 2)
		{
			while (min_counter - i++ > 0)
				ra(list);	
		}
		else
			if (min_counter == (3 - index))
			{
				rra(list);
				rra(list);			
			}
			else
				rra(list);	
		pb(list);	
}

void medium_solve(t_stacks *list)
{	
	rotate_and_push(list, 0);
	if (is_sorted(list->sorted_arr, list->arr_sizeA))
	{
		pa(list);
		return;		
	}	
	else if (list->arr_sizeA == 3)
	{
		short_solve(list);
		pa(list);
		return;
	}
	rotate_and_push(list, 1);
	if (!is_sorted(list->sorted_arr, list->arr_sizeA))
		short_solve(list);
	pa(list);
	pa(list);
}
