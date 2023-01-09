/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:36:01 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/09 16:03:31 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char **str, int arg_count)
{
	free_mem(str, arg_count);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int	ft_isdigit_negative(int c)
{
	if ((c >= 48 && c <= 57) || c == 45)
		return (1);
	else
		return (0);
}

int	check_int_limits(long int num)
{	
	if (num >= -2147483648 && num <= 2147483647)
		return (1);
	return (0);
}

int	is_sorted(const int *arr, int arr_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < arr_size - 1)
	{
		j = 0;
		while (j < arr_size - 1 - i)
		{
			if ((arr[j] > arr[j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted_args(int arg_count, char **args)
{
	int	j;	

	j = 0;	
	while (j < arg_count - 2)
	{
		if (ft_atoi(args[j]) > ft_atoi(args[j + 1]))
			return (0);
		j++;
	}
	return (1);
}

int	is_duplicated(int arg_count, char **args) 
{
	int	i;
	int	j;

	i = 0;
	while (i < arg_count)
	{
		j = i + 1;
		while (j < arg_count - 1)
		{
			if (ft_strncmp(args[i], args[j], (arg_count - 1)) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
