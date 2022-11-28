/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:56:37 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/11/28 20:11:31 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"

typedef struct s_stacks
{
	int *stackA;
	int *stackB;
	int arr_size;
	
}	t_stacks;


#endif

/* int *stackA;
	int *stackB;
	int arr_size;
	int i;
	int j;

	i = 0;	
	j = 1;
	arr_size = argc - 1;
	ft_printf("%d arguments", arr_size);
	ft_printf("\n\n");
	stackA = (int *)malloc(sizeof(int) * arr_size);
	stackB = (int *)malloc(sizeof(int) * arr_size);
	//stackA = NULL;
	stackB = NULL;
	
	while(arr_size > 0)
	{
		stackA[i] = ft_atoi(argv[j]);
		i++;
		j++;
		arr_size--;
		
	}
	ft_printf("Original Stack\n");
	j = 0;
	arr_size = argc - 1;
	while(j < arr_size)
		ft_printf("[%d]", stackA[j++]);
	ft_printf("\n\n");
	
	ft_printf("Sa - Swap the first 2 elements operation!\n");
	sa_sb_ss_swap(stackA);
	i = argc - 1;
	j = 0;
	while(i-- > 0)
		ft_printf("[%d]", stackA[j++]);
	ft_printf("\n\n");

	ft_printf("Pb - Push to stackB top of stackA\n");
	stackA = pa_pb_push(stackA, stackB, arr_size);
	i = argc - 1;
	j = 0;
	while(i-- > 0)
		ft_printf("[%d]", stackA[j++]);
	ft_printf("\n\n");
	
	//free(stackB);
	//free(stackA); */