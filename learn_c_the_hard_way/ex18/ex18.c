// C program to domenstrate a Pointer to Function.

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* Our old friend from ex17. */
void die(const char *message)
{
    if (errno)
    {
        perror(message);
    }
    else
    {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// A typedef creates a fake type, in this
// case for a function pointer.
// We can pass this as parameter to function.
typedef int (*compare_cb)(int a, int b);

// Another example for Pointer to function.
int (*sum)(int a, int b);   

/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting.
*/
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;

    // New array of integers in the heap using malloc function.
    int *target = malloc(count * sizeof(int));

    // Check if the momory is allocated or not.
    if (target == NULL)
    {
        die("Momory not allocated.\n");
        exit(1);
    }

    // Make our copy of the numbers array.
    memcpy(target, numbers, count * sizeof(int));

    // The outer loop of bubble sort.
    for (int i = 0; i < count; i++)
    {
        // The inner loop of bubble sort.
        for (int j = 0; j < count - 1; j++)
        {
            if (cmp(target[j], target[j + 1]) > 0)
            {
                int tmp = target[j + 1];
                target[j + 1] = target[j];
                target[j] = tmp;
            }
        }
    }

    return target;
}

// This fuction match the pointer signature.
int sorted_order(int a, int b)
{
    return a - b;
}

// This fuction match the pointer signature.
int reversed_order(int a, int b)
{
    return b - a;
}

// This fuction match the pointer signature.
int strange_order(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }

    return a % b;
}

void test_sorting(int *numbers, int count, compare_cb cmp)
{
    int *sorted = bubble_sort(numbers, count, cmp);

    if (!sorted)
    {
        die("Failed to sort as requested.\n");
    }

    int i = 0;
    for (int i = 0; i < count; i++)
    {
        printf("%d ", sorted[i]);
    }

    printf("\n");

    // Free the allocated memory for the integers array.
    free(sorted);

    // How to break it. (for fun)
    // Print the assembler byte code.
    unsigned char *data = (unsigned char *)cmp;

    for (int i = 0; i < 25; i++)
    {
        printf("%02x:", data[i]);
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        die("USAGE: ex18 12 33 2 4 1 88 12");
    }

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;
    int *numbers = malloc(count * sizeof(int));

    if (!numbers)
    {
        die("Memory error.");
    }

    for (int i = 0; i < count; i++)
    {
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reversed_order);
    test_sorting(numbers, count, strange_order);

    free(numbers);

    return 0;
}