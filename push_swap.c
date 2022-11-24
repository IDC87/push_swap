/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/11/24 20:59:38 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

void sort_small_list(int *numlist)
{
	
}

void error(void)
{
	ft_printf("Error\n");
	exit(0);
}

int main	(int argc, char **argv)
{
	int *Numlist;
	int i;
	int j;

	i = 0;	
	j = 1;
	ft_printf("%d arguments\n", argc);
	 Numlist = (int *)malloc(sizeof(int) * argc - 1);
	while(argc > 1)
	{
		Numlist[i] = ft_atoi(argv[j]);
		//Numlist[i] = argv[j];
		i++;
		j++;
		argc--;
		
	}
	
	while(i-- > 0)
	{
		ft_printf("%d position -> [%d]", i, *Numlist++);
		ft_printf("\n");
	}
	
	/* if (argc < 2)
	error; //it shoud give the prompt back with no args
	if(argc <= 5)
		sort_small_list(Numlist);  */
	return (0);
}