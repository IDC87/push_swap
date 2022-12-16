#include <stdio.h>
#include <stdlib.h>

// Define the structs for stackA and stackB
typedef struct stackA
{
    int *arrA;
    int arr_sizeA;
} stackA;

typedef struct stackB
{
    int *arrB;
    int arr_sizeB;
} stackB;

// Define the struct for t_stacks that contains stackA and stackB
typedef struct s_stacks
{
    stackA A;
    stackB B;
    int args_size;
} t_stacks;

// Function that receives a stackA** argument
void foo(stackA **var)
{
    // Do something with the stackA** argument
    printf("The size of stackA is: %d\n", (*var)->arr_sizeA);
}

int main(int argc, char *argv[])
{
    // Create a t_stacks object
    t_stacks stacks;

    // Set the size of stackA in the t_stacks object
    stacks.A.arr_sizeA = 10;

    // Call the foo function and pass the address of the stackA object in the t_stacks object
    foo(&(stacks.A));

    return 0;
}