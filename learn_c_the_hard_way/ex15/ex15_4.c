// C program to illustrate Array Name as Pointers in C.

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Declare an array.
    int var[] = {5, 10, 15};

    // Declare a pointer variable.
    int *ptr;

    // Assign address of var[0] to ptr.
    // We can use ptr = &var[0]; (both are same).
    ptr = var;

    
    return 0;
}
