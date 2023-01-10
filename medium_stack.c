/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:27:32 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/10 10:26:12 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_solve_two(t_stacks *S)
{
	if (S->sorted_arr[0] > S->sorted_arr[2])
		rra(S);
	else
	{
		sa(S);
		ra(S);
	}
}

void	short_solve(t_stacks *S)
{	
	if (S->sorted_arr[0] > S->sorted_arr[1])
	{
		if (S->arr_sizeA == 2)
		{
			sa(S);
			return ;
		}			
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
		short_solve_two(S);
	}	
}

int	find_smallest(const int *array, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			break ;
		i++;
	}
	return (i);
}

void	rotate_and_push(t_stacks *list, int index)
{
	int	min_counter;
	int	i;

	i = 0;
	min_counter = find_smallest(list->sorted_arr, list->arr_sizeA, index);
	if (min_counter <= list->arr_sizeA / 2)
	{
		while (min_counter - i++ > 0)
			ra(list);
	}
	else
	{
		if (min_counter == (3 - index))
		{
			rra(list);
			rra(list);
		}
		else
			rra(list);
	}
	pb(list);
}

void	medium_solve(t_stacks *list, int arg_count)
{
	if (arg_count - 1 <= 3)
		short_solve(list);
	else
	{
		rotate_and_push(list, 0);
		if (is_sorted(list->sorted_arr, list->arr_sizeA))
		{
			pa(list);
			return ;
		}	
		else if (list->arr_sizeA == 3)
		{
			short_solve(list);
			pa(list);
			return ;
		}
		rotate_and_push(list, 1);
		if (!is_sorted(list->sorted_arr, list->arr_sizeA))
			short_solve(list);
		pa(list);
		pa(list);
	}
}
