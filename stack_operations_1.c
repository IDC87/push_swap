/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:39:03 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/11 06:35:48 by ivda-cru         ###   ########.fr       */
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
	if (list->arr_size_a > 1)
	{
		rotate_up(&(list->sorted_arr), &(list->arr_size_a));
		ft_putendl_fd("ra", 1);
	}
}

void	rra(t_stacks *list)
{
	if (list->arr_size_a > 1)
	{
		rotate_down(&(list->sorted_arr), &(list->arr_size_a));
		ft_putendl_fd("rra", 1);
	}
}

void	pa(t_stacks *stack)
{
	int	popped;

	popped = pop_item(&(stack->arr_b), &(stack->arr_size_b));
	push_item(&(stack->sorted_arr), &(stack->arr_size_a), popped);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stacks *stack)
{
	int	popped;

	popped = pop_item(&(stack->sorted_arr), &(stack->arr_size_a));
	push_item(&(stack->arr_b), &(stack->arr_size_b), popped);
	ft_putendl_fd("pb", 1);
}
