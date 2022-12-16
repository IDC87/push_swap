/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:47 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/12/12 21:32:35 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _CRTDBG_MAP_ALLOC
#include "push_swap.h"
//#include <crtdbg.h>


/* typedef struct student {
    int age;
} student;

void addStudent(student *s) {
     Here we can use the arrow operator (->) to dereference 
       the pointer and access any of it's members: 
    s->age = 10;
}

int main(void) {

    student aStudent = {0};      create an instance of the student struct 
    addStudent(&aStudent);       pass a pointer to the instance 

    printf("%d", aStudent.age);

    return 0;
} */


//https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

int *intdup(int const *src, size_t len)
{
   int *p = (int *)malloc(len * sizeof(int));
   ft_memcpy(p, src, len * sizeof(int));
   return p;
}

/* void push_to_b(t_stacks *push)
{
	int *new_arrA;
	int *new_arrB;
	int tmp;
	int i;

	if (push->A.arr_sizeA != 0)
	{
		new_arrA = (int *)malloc(sizeof(int) * (push->A.arr_sizeA - 1));
		tmp = push->A.arrA[0];
		i = 0;
		while (i < (push->A.arr_sizeA - 1))
		{
			new_arrA[i] = push->A.arrA[i + 1];
			i++;
		}
		push->A.arr_sizeA--;
		 free(push->A.arrA);
		push->A.arrA = NULL;
		push->A.arrA = new_arrA;
		
		new_arrB = (int *)malloc(sizeof(int) * (push->B.arr_sizeB + 1));
		i = push->B.arr_sizeB + 1;
		while (i > 0)
		{
			new_arrB[i] = push->B.arrB[i - 1];
			i--;
		}
		push->B.arr_sizeB++;
		free(push->B.arrB);
		push->B.arrB = NULL;
		new_arrB[0] = tmp;
		push->B.arrB = new_arrB;
		
	}	
	
} */

void push_to_b(stackA **A, stackB **B)
{
	int *new_arrA;
	int *new_arrB;
	int tmp;
	int i;

	(*A)->arr_sizeA--;
	new_arrA = (int *)malloc(sizeof(int) * ((*A)->arr_sizeA));
	tmp = (*A)->arrA[0];
		i = 0;
		while (i < ((*A)->arr_sizeA - 1))
		{
			new_arrA[i] = (*A)->arrA[i + 1];
			i++;
		}
		 free((*A)->arrA);
		(*A)->arrA = NULL;
		(*A)->arrA = new_arrA;
		
		new_arrB = (int *)malloc(sizeof(int) * ((*B)->arr_sizeB + 1));
		i = (*B)->arr_sizeB + 1;
		while (i > 0)
		{
			new_arrB[i] = (*B)->arrB[i - 1];
			i--;
		}
		(*B)->arr_sizeB++;
		free((*B)->arrB);
		(*B)->arrB = NULL;
		new_arrB[0] = tmp;
		(*B)->arrB = new_arrB;	
	
}




void	sa_swap(t_stacks *swap)
{
	int tmp;

	tmp = 0;	
	if (swap->A.arr_sizeA > 1)	
	{
		tmp = swap->A.arrA[0];
		swap->A.arrA[0] = swap->A.arrA[1];
		swap->A.arrA[1] = tmp;		
	}
}

void	sb_swap(t_stacks *swap)
{
	int tmp;

	tmp = 0;
	if (swap->B.arr_sizeB > 1)	
	{
		tmp = swap->B.arrB[swap->B.arr_sizeB - 1];
		swap->B.arrB[swap->B.arr_sizeB - 1] = swap->B.arrB[swap->B.arr_sizeB - 2];
		swap->B.arrB[swap->B.arr_sizeB - 2] = tmp;		
	}
}

void	ss_swap(t_stacks *swap)
{
	sa_swap(swap);
	sb_swap(swap);
}

void error(void)
{
	ft_printf("Error\n");
	exit(0);
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
	//print_array(&stack);
	
	push_to_b(&(stack.A), &(stack.B));

	/* push_to_b(&stack.A, &stack.B);
	push_to_b(&stack.A, &stack.B);
	
	push_to_b(&stack.A, &stack.B);
	push_to_b(&stack.A, &stack.B);
	push_to_b(&stack.A, &stack.B); */
	
		
	/* sa_swap(&stack);
	sb_swap(&stack);
	push_a_to_b(&stack);
	push_a_to_b(&stack);
	push_a_to_b(&stack);
	ss_swap(&stack);	 */

	//print_array(&stack);
	print_test(&stack);


	//free(stack.A.arrA);
	//free(stack.B.arrB);	
	//free(&stack);
	return (0);
}