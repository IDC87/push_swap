/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:13:59 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/08 17:18:15 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



t_node *create_node(int args)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->value = args;
	new_node->next = NULL;
	return new_node;	
}

void insert_end(t_stack *list, t_node *new_node)
{
	if (list->head == NULL)
	{
		list->head = new_node;
		list->tail = new_node;
	}
	list->tail->next = new_node;
	list->tail = new_node;
}

void print_stack(t_stack *stack, t_node *curr)
{	
	curr = stack->head;
	while (curr != NULL)
	{
		ft_printf("%d\n", curr->value);
		curr = curr->next;
	}
	//ft_printf("\n");	
}

void free_nodes(t_stack *stack, t_node *curr)
{
	curr = stack->head;
	while (curr != NULL)
	{
		free(curr);
		curr = curr->next;
	}	
}

void sa_swap(t_node **node, t_stack *stack)
{
	int tmp;
	t_node *tmp_node;
	tmp_node = stack->head;
	
	if (*node != NULL && (*node)->next != NULL)
	{
		tmp = (*node)->value;
		(*node)->value = (*node)->next->value;
		(*node)->next->value = tmp;
		
		tmp_node = (*node)->next;
		(*node)->next = (*node)->next->next;
		tmp_node->next = *node;
		*node = tmp_node;


	}
	
}


int main (int argc, char **argv)
{
	t_stack *stack;
	t_node *new_node;
	int i;
	int value;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (1);
	stack->head = NULL;
	stack->tail = NULL;
	i = 1;

	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		new_node = create_node(value);
		insert_end(stack, new_node);
		i++;
	}
	sa_swap(&new_node, stack);
	print_stack(stack, new_node);
	free_nodes(stack, new_node);
	free(stack);
	

	
	return (0);
}