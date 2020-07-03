/* 
    Pointers 
    General syntax:
    datataype *var_name;
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    // An example pointer "ptr"
    int x = 10;
    int *ptr;
    *ptr = &x;

    printf("The address of (*ptr): %p\n", &ptr);
    printf("The value of (x): %d\n", x);

    *ptr = 20;
    printf("The address of (*ptr): %p\n", &ptr);
    printf("The value of (*ptr): %d\n", *ptr);

    *ptr = 30;
    printf("The address of (*ptr): %p\n", &ptr);
    printf("The value of (*ptr): %d\n", *ptr);

    return 0;
}