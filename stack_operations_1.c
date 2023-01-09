/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:39:03 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/09 16:29:44 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *swap)
{
	int	tmp;

	tmp = 0;
	tmp = swap->sorted_arr[0];
	swap->sorted_arr[0] = swap->sorted_arr[1];
	swap->sorted_arr[1] = tmp;
	ft_putendl_fd("sa", 1);
}

void	ra(t_stacks *list)
{	
	if (list->arr_sizeA > 1)
	{
		rotate_up(&(list->sorted_arr), &(list->arr_sizeA));
		ft_putendl_fd("ra", 1);
	}
}

void	rra(t_stacks *list)
{
	if (list->arr_sizeA > 1)
	{
		rotate_down(&(list->sorted_arr), &(list->arr_sizeA));
		ft_putendl_fd("rra", 1);
	}
}

void	pa(t_stacks *stack)
{
	int	popped;

	popped = pop_item(&(stack->arrB), &(stack->arr_sizeB));
	push_item(&(stack->sorted_arr), &(stack->arr_sizeA), popped);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stacks *stack)
{
	int	popped;

	popped = pop_item(&(stack->sorted_arr), &(stack->arr_sizeA));
	push_item(&(stack->arrB), &(stack->arr_sizeB), popped);
	ft_putendl_fd("pb", 1);
}
