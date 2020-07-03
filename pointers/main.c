#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 1; i < 100; i++)
    {
        if (i % 3 == 2 && i % 4 == 3 && i % 5 == 4)
        {
            printf("Found: %d\n", i);
        }
    }
    // for (int i = 100000; i < 100999; i++)
    // {
    //     if ((i % 9127) == 0)
    //     {
    //         printf("Found: %d\n", i);
    //         printf("%d\n", 0 % 55);
    //     }
    // }

    return 0;
}
