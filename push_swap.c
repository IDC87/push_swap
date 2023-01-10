/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/10 10:59:42 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mem(char **list, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	check_arguments(char **args, int arg_count)
{
	int	i;

	i = 0;
	if (arg_count == 1)
		exit(EXIT_SUCCESS);
	while (i < arg_count - 1)
	{
		if (!ft_isdigit_negative(args[i][0]))
			error(args, arg_count - 1);
		if (!check_int_limits(ft_atoi(args[i])))
			error(args, arg_count - 1);	
	i++;
	}
	if (is_duplicated(arg_count, args))
		error(args, arg_count - 1);
	if (is_sorted_args(arg_count, args) == 1)
	{
		free_mem(args, arg_count - 1);
		exit(EXIT_SUCCESS);
	}	
}

void	initiate_variables(t_stacks *stack, char **args, int arg_count)
{
	int	i;

	i = 0;
	stack->arr_sizeA = arg_count - 1;
	stack->arr_sizeB = 0;
	stack->arrA = (int *)malloc(sizeof(int) * stack->arr_sizeA);
	if (!stack->arrA)
		exit(EXIT_FAILURE);
	stack->sorted_arr = (int *)malloc(sizeof(int) * stack->arr_sizeA);
	if (!stack->sorted_arr)
		exit(EXIT_FAILURE);
	stack->arrB = NULL;
	stack->stringA = NULL;
	stack->stringB = NULL;
	stack->n_iterarions = 0;
	stack->bits = 9;
	while (i < stack->arr_sizeA)
	{		
		stack->sorted_arr[i] = ft_atoi(args[i]);
		stack->arrA[i] = ft_atoi(args[i]);
	i++;
	}
}

char	**check_arg_string(char **args, int *arg_count)
{
	char	**str;
	int		i;

	i = 0;
	if (*arg_count == 2)
	{
		str = ft_split(args[1], ' ');
		while (str[i] != NULL)
			i++;
		*arg_count = i + 1;
	}
	else
	{
		str = (char **)malloc(sizeof(char *) * (*arg_count - 1));
		if (!str)
			return (NULL);
		while (i < *arg_count - 1)
		{
			str[i] = ft_strdup(args[i + 1]);
			i++;
		}
	}	
	return (str);
}

int	main(int argc, char **argv)
{
	t_stacks	stack;
	char		**str;

	str = check_arg_string(argv, &argc);
	check_arguments(str, argc);
	initiate_variables(&stack, str, argc);
	bubble_sort(stack.sorted_arr, stack.arr_sizeA);
	index_group(stack.arrA, &stack.sorted_arr, stack.arr_sizeA);
	if (argc - 1 <= 5)
		medium_solve(&stack, argc - 1);
	else
		go_radix(&stack, argc - 1);	
	free(stack.arrA);
	free(stack.arrB);
	free(stack.sorted_arr);
	free_mem(str, argc - 1);
	return (EXIT_SUCCESS);
}