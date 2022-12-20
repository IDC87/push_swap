/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:36:01 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/20 18:46:25 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error(void)
{
	ft_printf("Error\n");
	exit(0);
}

int is_sorted(const int *arr, int arr_size, int arr_sizeB)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
		while (i < arr_size - 1)
		{
			j = 0;
			while(j < arr_size - 1 - i)
			{
				if ((arr[j] > arr[j + 1]) && (arr_sizeB == 0)) // ARRANJAR ISTO, TA WIERD
					return(0);								
				j++;				
			}
			i++;			
		}
		if (arr_sizeB == 0)
		return (1);
		else
		return (0);
}

int is_duplicated(const int *arr, int arr_size)
{
	int i;
	int j;
	
	i = 0;
		while (i < arr_size)
		{
			j = i + 1;
			while(j < arr_size)
			{
				if (arr[i] == arr[j])
					return(1);								
				j++;				
			}
			i++;			
		}
		return (0);
}







