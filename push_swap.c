/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/16 17:56:35 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e


void error(void)
{
	ft_printf("Error\n");
	exit(0);
}

/* void rotate(int **array, int length, int rotate_by) {
  // Allocate a new array to store the rotated elements
  int *new_array = malloc(length * sizeof(int));

  // Rotate the elements of the array by the specified amount
  for (int i = 0; i < length; i++) {
    int rotated_index = (i + rotate_by) % length;
    if (rotated_index < 0) {
      rotated_index += length;
    }
    new_array[rotated_index] = (*array)[i];
  }

  // Free the old array and update the array pointer to point to the new array
  free(*array);
  *array = new_array;
} */

/Rotate the given array by n times toward right    
    for(int i = 0; i < n; i++){    
        int j, last;    
        //Stores the last element of the array    
        last = arr[length-1];    
        
        for(j = length-1; j > 0; j--){    
            //Shift element of array by one    
            arr[j] = arr[j-1];    
        }    
        //Last element of array will be added to the start of array.    
        arr[0] = last;    
    }    


void rotate(int **arr, int *arr_size) 
{
	int *new_arr;
	int i;
	int rotated;
	
	new_arr = (int *)malloc(sizeof(int) * (*arr_size));
	i = 0;
	rotated = 1;
	while (i < (*arr_size))
	{
		rotated = (i + rotated) % (*arr_size);
		new_arr[rotated] = (*arr)[i];
		i++;	
	}
	free(*arr);
	ft_printf("AARAY SIZE INSIDE %d\n", (*arr_size));
	(*arr) = new_arr;
}

int main	(int argc, char **argv)
{
	t_stacks stack;
	int i;
	int j;
	
	i = 0;
	j = 1;
	
	stack.A.arr_sizeA = argc - 1;
	stack.B.arr_sizeB = 0;
	stack.args_size = argc - 1;
	stack.A.arrA = (int *)malloc(sizeof(int) * stack.A.arr_sizeA);
	stack.B.arrB = ft_calloc(argc - 1, sizeof(int));

	while(i < stack.A.arr_sizeA)
	{
		stack.A.arrA[i] = ft_atoi(argv[j]);
		i++;
		j++;		
	}
	
	ft_printf("ORIGINAL STACK\n\n");
	print_test(&stack);

	rotate(&(stack.A.arrA), &(stack.A.arr_sizeA)); 
	
	
	
	/* push_a_to_b(&stack);
	push_a_to_b(&stack);
	push_a_to_b(&stack);
	push_a_to_b(&stack);
	push_a_to_b(&stack);

	push_b_to_a(&stack);
	push_b_to_a(&stack);

	sa_swap(&stack);
	sb_swap(&stack);
	ss_swap(&stack); */

	


	

	
	print_test(&stack);

	free(stack.A.arrA);
	free(stack.B.arrB);	
	return (0);
}