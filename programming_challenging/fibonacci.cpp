#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int fibonacci_naive(int n)
{
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n)
{
    if (n <= 1)
        return n;

    vector<int> a(n + 1);
    int length = a.size();

    // Prepare fib sequence.
    a[0] = 0;
    a[1] = 1;

    for (int i = 2; i < length; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    return a[n];
}

int fibonacci_less_memory_fast(int n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; i++)
    {
        int temp = previous;
        previous = current;
        current = temp + previous;
    }

    return current;
}

void test_solution()
{
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));

    assert(fibonacci_less_memory_fast(3) == 2);
    assert(fibonacci_less_memory_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_less_memory_fast(n) == fibonacci_fast(n));
}

int main()
{
    int n = 0;
    std::cin >> n;

    // std::cout << fibonacci_naive(n) << '\n';
    test_solution();
    cout << fibonacci_fast(n) << '\n';
    cout << fibonacci_less_memory_fast(n) << '\n';
    return 0;
}
