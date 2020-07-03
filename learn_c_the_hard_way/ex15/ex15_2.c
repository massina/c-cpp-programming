// C program to demonstrate the use of * from pointers in C

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // A normal integer variable.
    int var = 10;

    // A pointer variable that hold the address of var.
    int *ptr = &var;

    // This line prints value at the address stored in ptr.
    // Value stored is value of variable var.
    printf("Value of var: %d\n", *ptr);

    // The output of this line may be different in different
    // runs even on the same machine.
    printf("Address of var: %p\n", ptr);

    // We can use ptr as lvalue (Left hand side assignment)
    // Value at address is now 20
    *ptr = 20;

    // This prints 20.
    printf("After doing *ptr = 20, *ptr is %d\n", *ptr);

    return 0;
}
