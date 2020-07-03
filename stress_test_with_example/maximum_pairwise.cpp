#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int MaxPairWiseProduct(const vector<int> &numbers)
{
    int result = 0;
    int n = numbers.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(numbers[i] * numbers[j] > result)
            {
                result = numbers[i] * numbers[j];
            }
        }
    }

    return result;
}
