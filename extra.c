/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 06:25:11 by ivda-cru          #+#    #+#             */
/*   Updated: 2023/01/12 08:18:29 by ivda-cru         ###   ########.fr       */
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

void	error(char **str, int arg_count)
{
	free_mem(str, arg_count);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

char	*pop_element(t_stacks *bits, char **arr_pop, int *size)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) *(bits->bits + 1));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, arr_pop[0], bits->bits + 1);
	free(arr_pop[0]);
	while (i < *size - 1)
	{
		arr_pop[i] = arr_pop[i + 1];
		i++;
	}
	(*size)--;
	return (tmp);
}
