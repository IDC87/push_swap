/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:27:32 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/07 02:35:20 by ivda-cru         ###   ########.fr       */
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

void medium_solve(t_stacks *list)
{
	int min_counter;
	int i;

	i = 0;

	//print_test(list);
	
	min_counter = find_smallest(list->sorted_arr, list->arr_sizeA, 0);
	if (min_counter <= list->arr_sizeA / 2)
	{
		while (min_counter - i > 0)
		{
			ra(list);
			i++;
		}		
	}
	else
		if (min_counter == 3)
		{
			rra(list);
			rra(list);			
		}
		else
			rra(list);	
	pb(list);
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
	min_counter = find_smallest(list->sorted_arr, list->arr_sizeA, 1);
	i = 0;
	if (min_counter <= list->arr_sizeA / 2)
	{
		while (min_counter - i > 0)
		{
			ra(list);
			i++;
		}		
	}
	else
		if (min_counter == 2)
		{
			rra(list);
			rra(list);			
		}
		else
			rra(list);
	pb(list);
	if (!is_sorted(list->sorted_arr, list->arr_sizeA))
		short_solve(list);
	pa(list);
	pa(list);


}