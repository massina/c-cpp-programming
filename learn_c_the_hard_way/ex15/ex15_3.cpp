// C++ program to illustrate Pointer Arithmetic in C/C++.

// #include <bits/stdc++.h>
#include <stdio.h>

// Driver program
int main(int argc, char const *argv[])
{
    // Declare an array.
    int v[3] = {10, 100, 200};

    // Declare a pointer variable.
    int *ptr;

    // Assign the address of v[0] to ptr.
    ptr = v;

    for (int i = 0; i < 3; i++)
    {
        printf("Value of *ptr: %d\n", *ptr);
        printf("Value of ptr: %p\n", ptr);

        // Increment pointer ptr by 1.
        ptr++;
    }

    return 0;
}
